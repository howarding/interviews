//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//
//spoilers alert... click to show requirements for atoi.
//
//Requirements for atoi:
//        The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

#include <iostream>

using namespace std;

class Solution_008 {
public:
    int myAtoi(string s) {
        int top = INT_MAX / 10;
        int top_remainder = INT_MAX % 10;
        int len = s.size();
        int result = 0;

        int i = 0;
        // Discard all spaces from the beginning of the input string.
        while(s[i] == ' ' && i < len)
            i++;
        if(i < len){
            // sign = +1, if it's positive number, otherwise sign = -1.
            int sign = 1;
            if(s[i] == '+')
                i++;
            else if(s[i] == '-'){
                sign = -1;
                i++;
            }
            for(;i < len; i++){
                // Traverse next digits of input and stop if it is not a digit.
                // End of string is also non-digit character.
                if(s[i] < '0' || s[i] > '9')
                    break;
                // Check overflow and underflow conditions.
                if(result > top || (result == top && s[i] - '0' > top_remainder))
                    // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
                    return sign == 1 ? INT_MAX : INT_MIN;

                // Append current digit to the result.
                result = result * 10 + (s[i] - '0');
            }
            // We have formed a valid number without any overflow/underflow.
            // Return it after multiplying it with its sign.
            result *= sign;
        }
        return result;

    }
};

//int main() {
//    string s = "21474836460";
//    Solution_008 sol{};
//    cout << sol.myAtoi(s) << endl;
//}