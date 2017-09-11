//Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
//
//postTweet(userId, tweetId): Compose a new tweet.
//getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
//follow(followerId, followeeId): Follower follows a followee.
//unfollow(followerId, followeeId): Follower unfollows a followee.
//Example:
//
//Twitter twitter = new Twitter();
//
//// User 1 posts a new tweet (id = 5).
//twitter.postTweet(1, 5);
//
//// User 1's news feed should return a list with 1 tweet id -> [5].
//twitter.getNewsFeed(1);
//
//// User 1 follows user 2.
//twitter.follow(1, 2);
//
//// User 2 posts a new tweet (id = 6).
//twitter.postTweet(2, 6);
//
//// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
//// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//twitter.getNewsFeed(1);
//
//// User 1 unfollows user 2.
//twitter.unfollow(1, 2);
//
//// User 1's news feed should return a list with 1 tweet id -> [5],
//// since user 1 is no longer following user 2.
//twitter.getNewsFeed(1);

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct Tweet {
    int id;
    int timeStamp;
    Tweet* next;
    Tweet(int id, int timeStamp): id(id), timeStamp(timeStamp), next(nullptr) {};
};

class User {
    int id;
public:
    unordered_set<int> followees;
    Tweet* tweets;

    User(int id) {
        this->id = id;
        tweets = nullptr;
    }

    void postTweet(int tweetId, int timeStamp) {
        Tweet* tweet = new Tweet(tweetId, timeStamp);
        tweet->next = tweets;
        tweets = tweet;
    }

    void follow(int id) {
        followees.insert(id);
    }

    void unfollow(int id) {
        followees.erase(id);
    }

};

struct cmp {
    bool operator() (Tweet* a, Tweet* b) {
        return a->timeStamp < b->timeStamp;
    }
};

class Twitter {
    int timeStamp;
    unordered_map<int, User*> users;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timeStamp = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (!users.count(userId))
            users[userId] = new User(userId);
        users[userId]->postTweet(tweetId, timeStamp++);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        if (!users.count(userId))
            return result;
        priority_queue<Tweet*, vector<Tweet*>, cmp> que;
        if (users[userId]->tweets)
            que.push(users[userId]->tweets);
        for (int user : users[userId]->followees)
            if (users[user]->tweets)
                que.push(users[user]->tweets);

        int i = 0;
        while (!que.empty() && i++ < 10) {
            Tweet* tweets = que.top();
            que.pop();
            result.push_back(tweets->id);
            if (tweets->next) que.push(tweets->next);
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (!users.count(followerId))
            users[followerId] = new User(followerId);
        if (!users.count(followeeId))
            users[followeeId] = new User(followeeId);
        users[followerId]->follow(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (!users.count(followerId)) return;
        users[followerId]->unfollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */