//List<Integer>getFriend(Integer id) api. Recommend K friends with most mutual friends.(produce a list of friend's friend)
//有getFriend()，推荐你的朋友的朋友做你的新朋友，这个新朋友不能是你原来的老朋友, 并且要按照共同好友的数量排序

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution_rf {
public:
    // return a vector of friends of user id.
    vector<int> getFriends(int id) {};

    // return a vector of potential friends. Friends are sorted according to # their mutual fiends with user id.
    vector<int> referFriends(int id) {
        auto friend_list(getFriends(id));
        unordered_set<int> friends(friend_list.begin(), friend_list.end());
        unordered_map<int, int> dict;
        for (int user : friends)
            for (int user2 : getFriends(user))
                if (user2 != id && friends.find(user2) == friends.end())
                    dict[user2]++;
        vector<vector<int>> buckets;
        for (auto &pair : dict)
            buckets.push_back({pair.first, pair.second});
        sort(buckets.begin(), buckets.end(), cmp);
        vector<int> result;
        for (auto &ele : buckets)
            result.push_back(ele[0]);
        return result;
    }

    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};