#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
public:
    /**
     * Standard Binary Search
     * @param vector<int> nums
     * @param int target
     * @return Index of the number equal to target
     */
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }


};

//int main() {
//
//}