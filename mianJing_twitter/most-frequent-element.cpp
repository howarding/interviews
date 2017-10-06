//给一个sorted array,找出出现频率最高的那个数，如果多个的话，返回任意一个即可

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution_mf {
public:
    // Time:	O(n)
    // Space:	O(1)
    int mostFrequent(vector<int> &nums) {
        int maxNum = nums[0];
        int maxLen = 1;
        int i = 0;
        while (i < nums.size()) {
            if (i + maxLen <= nums.size() && nums[i + maxLen - 1] == nums[i]) {
                maxNum = nums[i];
                int j = i + maxLen - 1;
                // can use binary search here.
                while (j < nums.size() && nums[j] == nums[j-1]) j++;
                maxLen = j - i;
                i = j;
            } else i++;
        }
        return maxNum;
    };
};


//int main() {
//    Solution_mf sol;
//    vector<int> nums({1,2,2,3,3,3,4,4,4,4});
//    cout << sol.mostFrequent(nums) << endl;
//}