#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

void countSort() {

}


void insertionSort(vector<int>& nums) {
    if (nums.empty()) return;

    for (int i = 1; i < nums.size(); i++) {
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] > nums[j+1])
                swap(nums[j], nums[j+1]);
        }
    }
}


//int main() {
//    vector<int> nums({9, 7, 6, 15, 16, 5, 10, 11});
//    insertionSort(nums);
//    for (int num : nums)
//        cout << num << "\t";
//}