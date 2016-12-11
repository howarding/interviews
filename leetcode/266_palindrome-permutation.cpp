//Given a string, determine if a permutation of the string could form a palindrome.
//
//For example,
//"code" -> False, "aab" -> True, "carerac" -> True.
//
//Hint:
//
//    1. Consider the palindromes of odd vs even length. What difference do you notice?
//    2. Count the frequency of each character.
//    3. If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

#include <iostream>

using namespace std;

class Solution_266 {
public:
    // Exp: https://discuss.leetcode.com/topic/21999/1-4-lines-python-ruby-c-c-java
    // Time:	O(n)
    // Space:	O(1)
    bool canPermutePalindrome(string s) {
        bitset<256> mp;
        for (char c : s) {
            mp.flip(c);
        }
        if (mp.count() > 1) return false;
        return true;
    }
};