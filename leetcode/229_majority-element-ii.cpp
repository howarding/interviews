//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

#include <iostream>
#include <vector>

using namespace std;

class Solution_229 {
public:
    // Exp: https://discuss.leetcode.com/topic/17564/boyer-moore-majority-vote-algorithm-and-my-elaboration
    // Exp: https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
    // Moore Voting Algorithm
    // Time:	O(n)
    // Space:	O(1)
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) return result;
        int element1 = 0, count1 = 0, element2 = 1, count2 = 0;
        for (int num : nums) {
            if (count1 == 0 && num != element2)
                element1 = num;
            else if (count2 == 0 && num != element1)
                element2 = num;
            if (element1 == num)
                count1++;
            else if (element2 == num)
                count2++;
            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int num : nums) {
            if (num == element1)
                count1++;
            else if (num == element2)
                count2++;
        }
        if (count1 > nums.size() / 3)
            result.push_back(element1);
        if (count2 > nums.size() / 3)
            result.push_back(element2);
        return result;
    }
};



//int main() {
//    Solution_229 sol;
//    vector<int> nums({1,2,2,3,2,1,1,3});
//    vector<int> result(sol.majorityElement(nums));
//    for (int num : result)
//        cout << num << '\t';
//}