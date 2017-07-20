//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
//
//Example 1
//Input: "2-1-1".
//
//    ((2-1)-1) = 0
//    (2-(1-1)) = 2
//    Output: [0, 2]
//
//
//Example 2
//Input: "2*3-4*5"
//
//    (2*(3-(4*5))) = -34
//    ((2*3)-(4*5)) = -14
//    ((2*(3-4))*5) = -10
//    (2*((3-4)*5)) = -10
//    (((2*3)-4)*5) = 10
//Output: [-34, -14, -10, -10, 10]

#include <iostream>
#include <vector>

using namespace std;

class Solution_241 {
public:
    // D&C, recursive (My own)
    // Time:	O(n)
    // Space:	O(n)
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return {};
        return compute(input, 0, input.size());
    }

    vector<int> compute(string& input, int start, int end) {
        vector<int> result;
        char sign('\0');
        for (int i = start; i < end; i++) {
            if (isdigit(input[i])) continue;
            sign = input[i];
            for (int val1 : compute(input, start, i))
                for (int val2 : compute(input, i+1, end))
                    result.push_back(
                            sign == '+' ?
                            val1 + val2 :
                            (sign == '-' ? val1 - val2 : val1 * val2)
                    );
        }
        if (!sign) result.push_back(stoi(input.substr(start, end - start)));
        return result;
    }




    // DP
    // Exp: https://discuss.leetcode.com/topic/19906/c-4ms-recursive-dp-solution-with-brief-explanation
    vector<int> diffWaysToCompute1(string input) {
        // TODO
    }
};


//int main() {
//    Solution_241 sol;
//    string input("2-1-1");
//    vector<int> result(sol.diffWaysToCompute(input));
//    for (int num : result)
//        cout << num << '\t';
//}