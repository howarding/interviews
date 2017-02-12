//一堆votes.   List<Vote>; Vote : { candidate,  timestamp}，(Q,T) represents at time T, a query Q comes. Each query may appear many times. (q1, t1), (q2,t2),(q1,t3),(q3,t4)
//Write a class, which contains a function of enQuery(T,Q) and a function TopK which will return K query, which appear most times within t.
//1. 问当前时刻T得票最高的人是谁。
//2. 问得票最高的前K个人.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class votedGetter {
    unordered_map<string, vector<int>> votes;
public:
    struct Vote {
        string candidate;
        int timestamp;

        Vote(string q, int t) : candidate(q), timestamp(t) {};
    };

    votedGetter() {

    }

    void enQuery(Vote vote) {
        votes[vote.candidate].push_back(vote.timestamp);
    }

    string getTop(int timestamp) {
        int top_count = -1;
        string top_candidate;
        for (auto &&ele : votes) {
            int count = getVoteCount(ele.second, timestamp);
            if (top_count < count) {
                top_candidate = ele.first;
                top_count = count;
            }
        }
        return top_candidate;
    }

    string getTopK(int timestamp, int k) {
        // Quick Select
        vector<pair<string, int>> candidate_votes;
        for (auto &&ele : votes)
            candidate_votes.push_back({ele.first, getVoteCount(ele.second, timestamp)});
        return quickSelect(candidate_votes, 0, candidate_votes.size() - 1, k);
    }

    string quickSelect(vector<pair<string, int>> &candidates, int left, int right, int k) {
        int i = partition(candidates, left, right);
        int len = i - left + 1;
        if (len == k) return candidates[i].first;
        if (len < k)
            return quickSelect(candidates, i + 1, right, k - len);
        else
            return quickSelect(candidates, left, i - 1, k);
    }

    int partition(vector<pair<string, int>> &candidates, int low, int high) {
        // Descending Order
        pair<string, int> pivot = candidates[low];
        int start = low++;
        while (low <= high) {
            if (candidates[low].second < pivot.second && candidates[high].second > pivot.second)
                swap(candidates[low++], candidates[high--]);
            if (candidates[low].second >= pivot.second) low++;
            if (candidates[high].second <= pivot.second) high--;
        }
        swap(candidates[start].second, candidates[high].second);
        return high;
    }

    int getVoteCount(vector<int> &vote_list, int t) {
        // LC 35
        // Search Insert Position
        int low = 0, high = vote_list.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vote_list[mid] == t)
                return mid + 1;
            if (vote_list[mid] < t)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + 1;
    }

};