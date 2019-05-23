//Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
//
//For example:
//
//Given s = "aabb", return ["abba", "baab"].
//
//Given s = "abc", return [].
//
//Hint:
//
//    1. If a palindromic permutation exists, we just need to generate the first half of the string.
//    2. To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.

#include <iostream>
#include <vector>

using namespace std;

class Solution_267 {
public:
    // 266 + 47
    // Exp: https://discuss.leetcode.com/topic/22214/ac-java-solution-with-explanation
    // Time:	O(n)
    // Space:	O(1)
    vector<string> generatePalindromes(string s) {
        vector<string> result;
        vector<int> count(256);
        for (char c : s)
            count[c]++;
        int odd = 0;
        for (int i : count)
            odd += i % 2;
        if (odd > 1) return result;

        string mid = "";
        vector<char> half;
        for (int i = 0; i < 256; i++) {
            if (count[i] % 2 != 0) mid += i;
            half.insert(half.end(), count[i] / 2, i);
        }
        getPerm(half, mid, 0, result);
        return result;
    }

    void getPerm(vector<char> half, string mid, int i, vector<string> &result) {
        if (half.empty() || i == half.size() - 1) {
            mid.insert(mid.end(), half.begin(), half.end());
            mid.insert(mid.begin(), half.rbegin(), half.rend());
            result.push_back(mid);
            return;
        }
        for (int k = i; k < half.size(); k++) {
            if (k != i && half[k] == half[i]) continue;
            swap(half[i], half[k]);
            getPerm(half, mid, i + 1, result);
        }
    }
};


//int main() {
//    Solution_267 sol;
//    string s = "aabb";
//    vector<string> result(sol.generatePalindromes(s));
//    for (string& ele: result)
//        cout << ele << endl;
//}