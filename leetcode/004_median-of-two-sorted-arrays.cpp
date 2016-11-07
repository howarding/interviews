//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is (2 + 3)/2 = 2.5


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	// Exp: https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation
	// Time:	O(log(m+n))
	// Space:	O(1)
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n)
			return findMedianSortedArrays(nums2, nums1);
		int i, j, imin = 0, imax = m, half = (m + n + 1) / 2;
		while (imin <= imax) {
			i = (imin + imax) / 2;
			j = half - i;
			if (i > 0 && nums1[i - 1] > nums2[j])
				imax = i - 1;
			else if (i < m && nums2[j - 1] > nums1[i])
				imin = i + 1;
			else
				break;
		}

		int num1, num2;
		if (i == 0) num1 = nums2[j - 1];
		else if (j == 0) num1 = nums1[i - 1];
		else num1 = max(nums1[i - 1], nums2[j - 1]);

		if ((m + n) & 1) return num1;
		if (i == m) num2 = nums2[j];
		else if (j == n) num2 = nums1[i];
		else num2 = min(nums1[i], nums2[j]);
		return (num1 + num2) / 2.0;
	}
};



int main() {
	vector<int> a = {1,3};
	vector<int> b = {2};
	Solution sol;
	double c = sol.findMedianSortedArrays(a, b);
	cout << c << endl;
}