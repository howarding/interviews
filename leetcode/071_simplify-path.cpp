//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//click to show corner cases.
//
//Corner Cases:
//    Did you consider the case where path = "/../"?
//    In this case, you should return "/".
//    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//    In this case, you should ignore redundant slashes and return "/home/foo".

#include <iostream>
#include <stack>

using namespace std;

class Solution_017 {
public:
    // Stack
    // Exp:
    // Time:	O(n)
    // Space:	O(n)
    string simplifyPath(string path) {
        stack<string> files;
        string file = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/' || i == path.size() - 1) {
                if (path[i] != '/')
                    file += path[i];
                if (file == "..") {
                    if (!files.empty())
                        files.pop();
                } else if (!file.empty() && file != ".")
                    files.push(file);
                file = "";
            } else
                file += path[i];
        }
        string result = "";
        while (!files.empty()) {
            result = "/" + files.top() + result;
            files.pop();
        }
        return result.empty() ? "/" : result;
    }
};