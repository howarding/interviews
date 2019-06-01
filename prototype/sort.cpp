#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& nums);
void countSort(vector<int>& nums);
void mergeSort(vector<int>& nums, int left, int right);
void mergeSort_merge(vector<int>& nums, int left, int mid, int right);
void quickSort(vector<int>& nums, int left, int right);
void quickSort2(vector<int>& nums, int left, int right);
void quickSort3(vector<int>& nums, int left, int right);
int partition(vector<int>& nums, int left, int right);


void countSort(vector<int>& nums) {}


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


// DC algorithm
// pivot 是左边数, right包括在内
// Exp: https://www.geeksforgeeks.org/quick-sort/
// Time:	avg: O(nlog(n)) worst: O(n^2) 当数组完全倒序时
// Space:	O(1)
void quickSort(vector<int>& nums, int left, int right) {
    int pivot = nums[left];     // pivot 是左边数
    int i = left + 1, j = right;
    while (i <= j) {
        if (nums[i] > pivot && nums[j] < pivot)
            swap(nums[i++], nums[j--]);
        if (nums[i] <= pivot) i++;
        if (nums[j] >= pivot) j--;
    }
    swap(nums[left], nums[j]);
    if (left < j) quickSort(nums, left, j - 1);
    if (j < right) quickSort(nums, j + 1, right);
}

// pivot 是右边数, right包括在内
// Time:	avg: O(nlog(n)) worst: O(n^2) 当数组完全倒序时
// Space:	O(1)
void quickSort2(vector<int>& nums, int left, int right) {
    int pivot = nums[right];     // pivot 是右边数
    int i = left, j = right - 1;
    while (i <= j) {
        if (nums[i] > pivot && nums[j] < pivot)
            swap(nums[i++], nums[j--]);
        if (nums[i] <= pivot) i++;
        if (nums[j] >= pivot) j--;
    }
    swap(nums[i], nums[right]);
    if (left < i) quickSort2(nums, left, i - 1);
    if (i < right) quickSort2(nums, i + 1, right);
}


// 用partition辅助，和quick select保持一致
// Time:	avg: O(nlog(n)) worst: O(n^2) 当数组完全倒序时
// Space:	O(1)
void quickSort3(vector<int>& nums, int left, int right) {
    int pi = partition(nums, left, right);
    if (left < pi) quickSort3(nums, left, pi - 1);
    if (pi < right) quickSort3(nums, pi + 1, right);
}

// pivot 是左边数, right包括在内
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];     // pivot 是左边数
    int i = left + 1, j = right;
    while (i <= j) {
        if (nums[i] > pivot && nums[j] < pivot)
            swap(nums[i++], nums[j--]);
        if (nums[i] <= pivot) i++;
        if (nums[j] >= pivot) j--;
    }
    swap(nums[left], nums[j]);
    return j;
}


//int main() {
//    vector<int> nums({9, 7, 6, 15, 16, 5, 10, 11});
//    insertionSort(nums);
//    mergeSort(nums, 0, nums.size());
//    quickSort(nums, 0, nums.size() - 1);
//    quickSort2(nums, 0, nums.size() - 1);
//    quickSort3(nums, 0, nums.size() - 1);
//    for (int num : nums)
//        cout << num << "\t";
//}