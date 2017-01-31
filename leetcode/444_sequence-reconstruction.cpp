//Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.
//
//Example 1:
//
//    Input:
//    org: [1,2,3], seqs: [[1,2],[1,3]]
//
//    Output:
//    false
//
//    Explanation:
//    [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
//Example 2:
//
//    Input:
//    org: [1,2,3], seqs: [[1,2]]
//
//    Output:
//    false
//
//    Explanation:
//    The reconstructed sequence can only be [1,2].
//Example 3:
//
//    Input:
//    org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
//
//    Output:
//    true
//
//    Explanation:
//    The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
//Example 4:
//
//    Input:
//    org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
//
//    Output:
//    true

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_444 {
public:
    // Exp: https://discuss.leetcode.com/topic/65633/very-short-solution-with-explanation
    // Time:	O(n)
    // Space:	O(n)
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        if (seqs.empty()) return false;
        int n = org.size();
        vector<int> ind(n + 1);
        vector<bool> pairs(n, false);
        unordered_set<int> nums;

        for (int i = 0; i < n; i++)
            ind[org[i]] = i;

        for (auto seq :seqs)
            for (int i = 0; i < seq.size(); i++) {
                nums.insert(seq[i]);
                if (seq[i] > n || seq[i] < 0)
                    return false;
                if (i > 0 && ind[seq[i - 1]] >= ind[seq[i]])
                    return false;
                if (i > 0 && ind[seq[i - 1]] + 1 == ind[seq[i]])
                    pairs[ind[seq[i - 1]]] = true;
            }

        for (int i = 0; i < n - 1; i++)
            if (!pairs[i])
                return false;
        if (nums.size() != n) return false;
        return true;
    }
};