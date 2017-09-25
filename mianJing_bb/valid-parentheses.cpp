//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution_vp {
public:
    bool isValid(string s) {
        unordered_map<char, char> dict({{'(', ')'}, {'{', '}'}, {'[', ']'}});
        stack<char> stk;
        for (char c : s) {
            if (dict.find(c) != dict.end()) {
                stk.push(c);
                continue;
            } else if (stk.empty() || dict[stk.top()] != c)
                return false;
            stk.pop();
        }
        return stk.empty();
    }


//Follow Up:
//1. 如果用户想设定matched pairs, 应该怎么做, 比如想设置 '/' 和 '\' match,  '^' 和 '*' match;  这里假设matched pairs are one-to-one and unique,  比如不存在 '/' 和 '\' match, 并且 '/' 也和 '|' match的情况. 让我自己设计个函数, 规定输入的参数.
//    我就做了个map 参数,  比如  boolean isValid(String input, Map<Character, Character> map),  用map来做检查
//2. 如果不同的人只在乎部分括号怎么办：类似 adam 只在乎""{}""， 那""...()[""就return true，""(){"" return false
//3. 需要加入单引号的判断，比如 " '[' ']' " 这样是valid， " '[ ]' " 这样不是valid，" ']' '[' " 也不是valid，括号之间可以有其它的各种character，比如数字，字母.

    bool isValid_fu12(string s, unordered_map<char, char> dict) {
        unordered_set<char> symbols;
        for (auto&& pair : dict) {
            symbols.insert(pair.first);
            symbols.insert(pair.second);
        }

        stack<char> stk;
        for (char c : s) {
            if (symbols.find(c) == symbols.end()) continue;
            if (dict.find(c) != dict.end()) {
                stk.push(c);
                continue;
            } else if (stk.empty() || dict[stk.top()] != c)
                return false;
            stk.pop();
        }
        return stk.empty();
    }


};


