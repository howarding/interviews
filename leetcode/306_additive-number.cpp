//Additive number is a string whose digits can form additive sequence.
//
//A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
//For example:
//"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
//
//1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
//1 + 99 = 100, 99 + 100 = 199
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
//
//Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
//
//Follow up:
//How would you handle overflow for very large input integers?

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution_306 {
public:
    bool isAdditiveNumber(string num) {
        string first, second;
        for (int i = 1; i <= num.size() / 2; i++)
            for (int j = 1; j <= (num.size()-i)/2; j++) {
                first = num.substr(0, i);
                second = num.substr(i, j);
                if (helper(num, i+j, first, second)) return true;
            }
        return false;
    }

    bool helper(string& num, int start, string& first, string& second) {
        if (start == num.size()) return true;
        for (int i = start + 1; i <= num.size(); i++) {
            while (num[i] == '0') i++;
            string third = num.substr(start, i - start);
            if ((first.empty()|| second.empty()) && i < num.size())
                return helper(num, i, second, third);
            if (additive(first, second, third) && helper(num, i, second, third))
                return true;
        }
        return false;
    }

    bool additive(string first, string second, string third) {
        if (third.size() < first.size() || third.size() < second.size()) return false;
        int carry = 0, m = first.size(), n = second.size(), l = third.size();
        for (int i = 0; i < max(m, n); i++) {
            int a = i < m ? first[m-1-i] - '0' : 0;
            int b = i < n ? second[n-1-i] - '0' : 0;
            int c = third[l-1-i] - '0';
            int total = a + b + carry;
            if (total % 10 != c) return false;
            carry = total / 10;
        }
        if (l == max(m, n) + 1) return third[0] - '0' == carry;
        return true;
    }
};



int main() {
    Solution_306 sol;
    string num = "1203";
    cout << sol.isAdditiveNumber(num) << endl;
}