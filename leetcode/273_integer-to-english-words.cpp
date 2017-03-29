//Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
//
//For example,
//    123 -> "One Hundred Twenty Three"
//    12345 -> "Twelve Thousand Three Hundred Forty Five"
//    1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//Hint:
//
//    1. Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
//    2. Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
//    3. There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

#include <iostream>
#include <vector>

using namespace std;

// Exp: https://discuss.leetcode.com/topic/23054/my-clean-java-solution-very-easy-to-understand
// Time:	O(log(n))
// Space:	O(log(n))
class Solution_273 {
    vector<string> LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                   "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                   "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if (!num) return "Zero";
        int i = 0;
        string result = "";
        while (num) {
            if (num % 1000)
                result = helper(num % 1000) + THOUSANDS[i] + " " + result;
            num /= 1000;
            i++;
        }
        while (result.back() == ' ')
            result.pop_back();
        return result;
    }

    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return LESS_THAN_20[num] + " ";
        else if (num < 100)
            return TENS[num / 10] + " " + helper(num % 10);
        else
            return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
    }
};