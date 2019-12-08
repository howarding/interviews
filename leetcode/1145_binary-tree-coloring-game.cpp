//Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of
// nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.
//Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n
// and y != x.  The first player colors the node with value x red, and the second player colors the node with value y blue.
//Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their color
// (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right
// child, or parent of the chosen node.)
//If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass
// their turn, the game ends, and the winner is the player that colored more nodes.
//You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it is
// not possible, return false.
//
//Example 1:
//    Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
//    Output: true
//    Explanation: The second player can choose the node with value 2.
//
//Constraints:
//    root is the root of a binary tree with n nodes and distinct node values from 1 to n.
//    n is odd.
//    1 <= x <= n <= 100

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // BEST:    PostOrder DFS
    // https://leetcode.com/problems/binary-tree-coloring-game/discuss/350570/JavaC%2B%2BPython-Simple-recursion-and-Follow-Up
    // Time:    O(n)
    // Space:   O(h) for recursion
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int left = 0, right = 0;
        numOfNodes(root, left, right, x);
        return max(max(left, right), n - left - right - 1) > n /2;
    }

    int numOfNodes(TreeNode* node, int& left, int& right, int x) {
        int l = node->left ? numOfNodes(node->left, left, right, x) : 0;
        int r = node->right ? numOfNodes(node->right, left, right, x) : 0;
        if (node->val == x) {
            left = l;
            right = r;
        }
        return 1 + l + r;
    }



    // My own
    // Time:    O(n)
    // Space:   O(n)
    bool btreeGameWinningMove1(TreeNode* root, int n, int x) {
        unordered_map<int, vector<int >> adj;
        if (!root) return false;
        helper(root, adj);
        vector<int> counts;
        unordered_set<int> visited;
        for (int neighbor: adj[x]) {
            visited.insert(x);
            counts.push_back(numOfNodes(neighbor, adj, visited));
            visited.clear();
        }
        sort(counts.begin(), counts.end());
        if (counts.size() == 1) return true;
        int count1 = 0;
        for (int i = 0; i < counts.size() - 1; i++)
            count1 += counts[i];
        return counts.back() > count1 + 1;
    }

    void helper(TreeNode* node, unordered_map<int, vector<int>>& adj) {
        if (node->left) {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            helper(node->left, adj);
        }
        if (node->right) {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            helper(node->right, adj);
        }
    }

    // DFS
    int numOfNodes(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(node);
        int result = 1;
        for (int neighbor: adj[node])
            if (visited.find(neighbor) == visited.end())
                result += numOfNodes(neighbor, adj, visited);
        return result;
    }
};