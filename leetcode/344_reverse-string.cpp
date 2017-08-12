//Write a function that takes a string as input and returns the string reversed.
//
//Example:
//Given s = "hello", return "olleh".

#include <iostream>

using namespace std;

class Solution_344 {
public:
    // 2 Pointers (My own)
    // Time:	O(n)
    // Space:	O(1)
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            swap(s[i++], s[j--]);
        return s;
    }
};



//int main() {
//    Solution_344 sol;
//    string s("hello");
//    cout << sol.reverseString(s) << endl;
//}