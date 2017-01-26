//You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
//
//Write a function to determine if the starting player can guarantee a win.
//
//For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".
//
//Follow up:
//Derive your algorithm's runtime complexity.

#include <iostream>

using namespace std;

class Solution_294 {
public:
    // Exp: https://discuss.leetcode.com/topic/27282/theory-matters-from-backtracking-128ms-to-dp-0ms
    // Time:    O(N!!)
    // Space:   O(1)
    bool canWin(string s) {
        return dfs(s);
    }

    bool dfs(string s) {
        for (int i = 1; i < s.size(); i++)
            if (s[i] == '+' && s[i - 1] == '+')
                if (!dfs(s.substr(0, i - 1) + "--" + s.substr(i + 1)))
                    return true;
        return false;
    }
};


//int main() {
//    string s = "+++++++++";
//    Solution_294 sol;
//    cout << sol.canWin(s) << endl;
//}