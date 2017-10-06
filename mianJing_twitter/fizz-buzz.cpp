//Write a program that outputs the string representation of numbers from 1 to n.
//
//But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
//
//Example:
//
//    n = 15,
//
//    Return:
//    [
//        "1",
//        "2",
//        "Fizz",
//        "4",
//        "Buzz",
//        "Fizz",
//        "7",
//        "8",
//        "Fizz",
//        "Buzz",
//        "11",
//        "Fizz",
//        "13",
//        "14",
//        "FizzBuzz"
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_412 {
public:
    // Math
    // Time:	O(n)
    // Space:	O(1)
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        string a("Fizz"), b("Buzz"), c("FizzBuzz");
        if (n <= 0) return result;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) result.push_back(c);
            else if (i % 5 == 0) result.push_back(b);
            else if (i % 3 == 0) result.push_back(a);
            else result.push_back(to_string(i));
        }
        return result;
    }
};