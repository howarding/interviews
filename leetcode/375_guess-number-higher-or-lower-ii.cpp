//We are playing the Guess Game. The game is as follows:
//
//I pick a number from 1 to n. You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
//However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
//
//Example:
//
//    n = 10, I pick 8.
//
//    First round:  You guess 5, I tell you that it's higher. You pay $5.
//    Second round: You guess 7, I tell you that it's higher. You pay $7.
//    Third round:  You guess 9, I tell you that it's lower. You pay $9.
//
//    Game over. 8 is the number I picked.
//
//    You end up paying $5 + $7 + $9 = $21.
//    Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
//
//Hint:
//
//    1. The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
//    2. Take a small example (n = 3). What do you end up paying in the worst case?
//    3. Check out this article if you're still stuck.
//    4. The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
//    5. As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?

#include <iostream>
#include <vector>

using namespace std;

class Solution_375 {
public:
    // Exp: https://discuss.leetcode.com/topic/51353/simple-dp-solution-with-explanation
    // DP
    // Time:	O(n^2)
    // Space:	O(n)
    int getMoneyAmount(int n) {
        vector<vector<int>> miniMax(n + 1, vector<int>(n + 1, 0));
        for (int j = 2; j <= n; j++)
            for (int i = j - 1; i > 0; i--) {
                int minimum = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    minimum = min(minimum, k + max(miniMax[i][k - 1], miniMax[k + 1][j]));
                miniMax[i][j] = min(minimum, min(i + miniMax[i + 1][j], j + miniMax[i][j - 1]));
            }
        return miniMax[1][n];
    }


    // Exp: https://discuss.leetcode.com/topic/51353/simple-dp-solution-with-explanation
    // Backtracking
    // Time:	O(n^2)
    // Space:	O(n)
    int getMoneyAmount_1(int n) {
        vector<vector<int>> miniMax(n + 1, vector<int>(n + 1, 0));
        return DP(miniMax, 1, n);
    }

    int DP(vector<vector<int>> &miniMax, int low, int high) {
        if (low >= high) return 0;
        if (miniMax[low][high]) return miniMax[low][high];
        int minimum = INT_MAX;
        for (int k = low; k <= high; k++)
            minimum = min(minimum, k + max(DP(miniMax, low, k - 1), DP(miniMax, k + 1, high)));
        miniMax[low][high] = minimum;
        return minimum;
    }
};