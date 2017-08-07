#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& nums);
void mergeSort(vector<int>& nums, int left, int right);
void mergeSort_merge(vector<int>& nums, int left, int mid, int right);
void quickSort(vector<int>& nums, int left, int right);
void countSort() {

}


// Time:	O(n^2)
// Space:	O(1)
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



// Exp: http://www.geeksforgeeks.org/merge-sort/
// Exp: LC88    https://leetcode.com/problems/merge-sorted-array/description/
// Time:	O(nlog(n))
// Space:	O(n)
void mergeSort(vector<int>& nums, int left, int right) {
    int mid = (left + right) / 2;
    if (mid == left) return;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid, right);
    mergeSort_merge(nums, left, mid, right);
}

void mergeSort_merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> array(nums.begin() + mid, nums.begin() + right);
    int m = mid - left, n = right - mid;
    int i = m - 1, j = n - 1, ind = m + n - 1;
    while (i >= 0 && j >= 0)
        nums[left + ind--] = nums[left + i] > array[j] ? nums[left + i--] : array[j--];
    while (j >= 0)
        nums[left + ind--] = array[j--];
}



// Exp: http://www.algolist.net/Algorithms/Sorting/Quicksort
// Time:	avg: O(nlog(n)) worst: O(n^2)
// Space:	O(1)
void quickSort(vector<int>& nums, int left, int right) {
    int mid = (left + right) / 2;
    if (mid == left) return;
    int i = left, j = right - 1, pivot = nums[mid];
    while (i <= j) {
        while (nums[i] < pivot)
            i++;
        while (nums[j] > pivot)
            j--;
        if (i <= j)
            swap(nums[i++], nums[j--]);
    }
    if (left < j)
        quickSort(nums, left, i);
    if (i < right)
        quickSort(nums, i, right);
}


int main() {
    vector<int> nums({9, 7, 6, 15, 16, 5, 10, 11});
//    insertionSort(nums);
//    mergeSort(nums, 0, nums.size());
    quickSort(nums, 0, nums.size());
    for (int num : nums)
        cout << num << "\t";
}