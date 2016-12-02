//Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
//
//To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
//
//Example:
//
//    Input:
//A = [ 1, 2]
//B = [-2,-1]
//C = [-1, 2]
//D = [ 0, 2]
//
//Output:
//2
//
//Explanation:
//    The two tuples are:
//1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution_454 {
public:
    // Exp: https://discuss.leetcode.com/topic/67594/concise-hash-map-o-n-2-solution-with-explanation-c
    // Time:	O(n^2)
    // Space:	O(n)
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        map<int, int> m1, m2;
        fillMap(A, B, m1);
        fillMap(C, D, m2);
        int total = 0;
        for (auto &&ele : m1) {
            auto it = m2.find(-ele.first);
            if (it != m2.end())
                total += ele.second * it->second;
        }
        return total;
    }

    void fillMap(vector<int> &A, vector<int> &B, map<int, int> &m) {
        int n = A.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m[A[i] + B[j]]++;
    }
};