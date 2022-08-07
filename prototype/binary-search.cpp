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

    void sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }

    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1]) return false;
        return true;
    }

    int findFirstIndex(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        // If target is in the array, return left, else return -1
        int result = nums[left] == target ? left : -1;
        return result;
    }

    int findLastIndex(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        // If target is in the array, return right, else return -1
        int result = nums[right] == target ? right : -1;
        return result;
    }


};

//int main() {
//
//}