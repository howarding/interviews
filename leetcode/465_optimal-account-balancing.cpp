//A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].
//
//Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.
//
//Note:
//
//    1. A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
//    2. Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.
//
//Example 1:
//
//    Input:
//    [[0,1,10], [2,0,5]]
//
//    Output:
//    2
//
//    Explanation:
//    Person #0 gave person #1 $10.
//    Person #2 gave person #0 $5.
//
//    Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
//
//Example 2:
//
//    Input:
//    [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
//
//    Output:
//    1
//
//    Explanation:
//    Person #0 gave person #1 $10.
//    Person #1 gave person #0 $1.
//    Person #1 gave person #2 $5.
//    Person #2 gave person #0 $5.
//
//Therefore, person #1 only need to give person #0 $4, and all debt is settled.

#include <vector>
#include <unordered_map>

using namespace std;

class Solution_465 {
public:
    // Recursion
    // Exp: https://leetcode.com/problems/optimal-account-balancing/discuss/95355/11-liner-9ms-DFS-solution-(detailed-explanation)
    // Time:    O(n!)       T(n) = (n-1)*T(n-1)
    // Space:   O(n)
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> balance;
        vector<long> debt;
        for (const vector<int>& transaction: transactions) {
            balance[transaction[0]] -= transaction[2];
            balance[transaction[1]] += transaction[2];
        }
        for (auto&& pair: balance)
            if (pair.second)
                debt.push_back(pair.second);
        return helper(debt, 0);
    }

    // min number of transactions to settle from start
    int helper(vector<long>& debt, int start) {
        while (start < debt.size() && !debt[start]) start++;    // get next non-zero debt
        int result = INT_MAX;
        for (int i = start + 1; i < debt.size(); i++)
            if (debt[i] * debt[start] < 0) {
                debt[i] += debt[start]; // start的钱全给i了, 以后都不用考虑start了
                result = min(result, helper(debt, start+1) + 1);
                debt[i] -= debt[start];
            }
        return result < INT_MAX ? result : 0;
    }
};