//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Some examples:
//    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_150 {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty()) return 0;
        stack<int> operands;
        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0]) || tokens[i].size() > 1) {
                operands.push(stoi(tokens[i]));
                continue;
            }
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            int result;
            if (tokens[i] == "+")
                result = a + b;
            else if (tokens[i] == "-")
                result = a - b;
            else if (tokens[i] == "*")
                result = a * b;
            else
                result = a / b;
            operands.push(result);
        }
        return operands.top();
    }
};


//int main() {
//    vector<string> tokens({"0", "3", "/"});
//    Solution_150 sol;
//    cout << sol.evalRPN(tokens) << endl;
//}