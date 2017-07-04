//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//        Given sorted array nums = [1,1,1,2,2,3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

#include <iostream>
#include <vector>

using namespace std;

class Solution_080 {
public:
    // In-place replace.
    // Time:	O(n)
    // Space:	O(1)
    int removeDuplicates(vector<int>& nums) {
        int N = 2;
        if (nums.size() <= N) return nums.size();
        int index = 0, dup = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[index] != nums[i]){
                nums[++index] = nums[i];
                dup = 1;
            }
            else if (dup++ < N)
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};