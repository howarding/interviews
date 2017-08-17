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
#include <sstream>
#include <iterator>

using namespace std;

class Solution_150 {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty()) return 0;
        stack<int> operands;

        for (string& s : tokens) {
            if (isdigit(s[0]) || s.size() > 1) {
                operands.push(stoi(s));
                continue;
            }
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            int result;
            if (s == "+")
                result = a + b;
            else if (s == "-")
                result = a - b;
            else if (s == "*")
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


//int main() {
//    Solution_150 sol;
//    string str;
//    int n;
//    getline(cin, str);
//    stringstream myStream(str);
//    myStream >> n;
//    for (int i = 0; i < n; i++) {
//        str.clear();
//        getline(cin, str);
//        istringstream buf(str);
//        vector<string> tokens{
//                istream_iterator<string>(buf),
//                istream_iterator<string>()
//        };
//        cout << sol.evalRPN(tokens) << endl;
//    }
//    return 0;
//}