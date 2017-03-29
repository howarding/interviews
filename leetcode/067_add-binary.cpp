//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

#include <iostream>
#include <vector>

using namespace std;

class Solution_067 {
public:
    // Exp: My own
    // Time:    O(n)
    // Space:    O(n)
    string addBinary(string a, string b) {
        string s;
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int av = i >= 0 ? a[i] - '0' : 0;
            int bv = j >= 0 ? b[j] - '0' : 0;
            int val = (av + bv + carry) % 2;
            carry = (av + bv + carry) / 2;
            char c = '0' + val;
            s = c + s;
        }
        if (carry)
            s = '1' + s;
        return s;
    }


    // FU 1. what if it supports different bases ? e.g: base 10, 16
    string addBinary_fb_fu1(string a, string b) {
        string s;
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int av = i >= 0 ? a[i] >= 'a' ? a[i] - 'a' + 10 : a[i] - '0' : 0;
            int bv = j >= 0 ? b[j] >= 'a' ? b[j] - 'a' + 10 : b[j] - '0' : 0;
            int val = (av + bv + carry) % 16;
            carry = (av + bv + carry) / 16;
            char c = val > 9 ? 'a' + val - 10 : '0' + val;
            s = c + s;
        }
        if (carry) {
            char c = carry > 9 ? 'a' + carry - 10 : '0' + carry;
            s = c + s;
        }
        return s;
    }

    // FU 2. 如果不是只加兩個數 是加a list of string nums
    string addBinary_fb_fu2(vector<string> nums) {
        string s;
        if (nums.empty()) return s;
        int n = 0, carry = 0;
        for (string &num : nums)
            n = max(n, int(num.size()));
        for (int i = 1; i <= n; i++) {
            int total = carry;
            for (string &num: nums) {
                total += i <= num.size() ? num[num.size() - i] - '0' : 0;
            }
            int val = total % 2;
            carry = total / 2;
            char c = '0' + val;
            s = c + s;
        }
        while (carry) {
            int val = carry % 2;
            carry /= 2;
            char c = '0' + val;
            s = c + s;
        }
        return s;
    }
};


//int main() {
//    Solution_067 sol;
////    vector<string> nums({"111", "111", "111", "111"});
//    vector<string> nums({"1", "11"});
//    cout << sol.addBinary_fb_fu2(nums) << endl;
//    cout << sol.addBinary_fb_fu1("ff", "a9") << endl;
//}