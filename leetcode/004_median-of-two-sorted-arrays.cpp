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

class Solution_004 {
public:
    // BEST
    // Exp1: https://www.youtube.com/watch?v=LPFhl65R7ww
    // Exp2: https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
    // Binary Search
    // Time:    O(log(min(m, n)))
    // Space:   O(1)
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();

        // Binary Search on the shorter array
        int left = 0, right = m, half = (m + n + 1) / 2;
        while (left <= right) {
            int mid1 = (left + right) / 2;
            int mid2 = half - mid1;

            // if mid1 is 0, it means nothing is there on left side. Use INT_MIN for maxLeft1
            // if mid1 is length of input, it means nothing is on right side. Use INT_MAX for minRight1
            int maxLeft1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int minRight1 = (mid1 == m) ? INT_MAX : nums1[mid1];

            int maxLeft2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int minRight2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // We have partitioned arrays at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size
                if ((m + n) % 2 == 0)
                    return (max(maxLeft1, maxLeft2) * 1.0 + min(minRight1, minRight2)) / 2;
                else
                    return max(maxLeft1, maxLeft2);
            } else if (maxLeft1 > minRight2)
                right = mid1 - 1;
            else
                left = mid1 + 1;
        }
        return 0;
    }


    // Exp: https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation
    // Time:	O(log(m+n))
    // Space:	O(1)
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays1(nums2, nums1);
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


//int main() {
//    vector<int> a = {1, 3};
//    vector<int> b = {2};
//    Solution sol;
//    double c = sol.findMedianSortedArrays(a, b);
//    cout << c << endl;
//}