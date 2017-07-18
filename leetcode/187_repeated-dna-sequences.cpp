//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
//For example,
//
//    Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//    Return:
//    ["AAAAACCCCC", "CCCCCAAAAA"].

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution_187 {
public:
    // Exp: https://discuss.leetcode.com/topic/8894/clean-java-solution-hashmap-bits-manipulation
    // Time:	O(n)
    // Space:	O(n)
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_set<int> DnaSequences, DuplicateSequences;
        unordered_map<char, int> dict({{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}});
        int sequence(0);
        for (int i = 0; i < s.size(); i++) {
            sequence <<= 2;
            sequence |= dict[s[i]];
            if (i < 9) continue;
            sequence &= 0xfffff;
            if (DnaSequences.find(sequence) == DnaSequences.end())
                DnaSequences.insert(sequence);
            else if (DuplicateSequences.find(sequence) == DuplicateSequences.end()) {
                result.push_back(s.substr(i-9, 10));
                DuplicateSequences.insert(sequence);
            }
        }
        return result;
    }
};


//int main() {
//    Solution_187 sol;
//    string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
//    vector<string> result(sol.findRepeatedDnaSequences(s));
//    for (string& str : result)
//        cout << str << endl;
//}