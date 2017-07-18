//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

class Solution_220 {
public:
    // Bucket check
    // Exp: https://discuss.leetcode.com/topic/15199/ac-o-n-solution-in-java-using-buckets-with-explanation
    // Time:	O(n)
    // Space:	O(k)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        unordered_map<long, long> map;
        for (int i = 0; i < nums.size(); i++) {
            long remappedNum = long(nums[i]) - INT_MIN;
            long bucket = remappedNum / (long(t) + 1); // why t+1 ? because, if t not plus 1, when t == 0, num divide by 0 will cause crash.

            if (map.count(bucket)
                // means the key in the map duplicated, it means there must exist two numbers that the different value between them are less than t
                    || (map.count(bucket-1) && remappedNum - map[bucket-1] <= t)
                    // if the two different numbers are located in two adjacent bucket, the value still might be less than t
                    || (map.count(bucket+1) && map[bucket+1] - remappedNum <= t))
                return true;    // the same reason for -1
            if (map.size() >= k) {
                long lastBucket = (long(nums[i - k]) - INT_MIN) / (long(t) + 1);
                map.erase(lastBucket);  //replace the duplicated key
            }
            map[bucket] = remappedNum;
        }
        return false;
    }



    // Exp: https://discuss.leetcode.com/topic/18453/c-using-set-less-10-lines-with-simple-explanation
    // Time:	O(n*log(k))     set.insert, erase, lower_bound cause O(log(k))
    // Space:	O(k)
    bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        set<long> window; // set is ordered automatically
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound(long(nums[i]) - t); // x-nums[i] >= -t ==> x >= nums[i]-t
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && *pos - long(nums[i]) <= t) return true;
            window.insert(long(nums[i]));
        }
        return false;
    }
};