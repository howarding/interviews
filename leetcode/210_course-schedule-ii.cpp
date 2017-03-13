//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
//
//For example:
//
//    2, [[1,0]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
//
//    4, [[1,0],[2,0],[3,1],[3,2]]
//There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
//
//Note:
//    1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
//    2. You may assume that there are no duplicate edges in the input prerequisites.
//click to show more hints.
//
//Hints:
//    1. This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
//    2. Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
//    3. Topological sort could also be done via BFS.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution_210 {
public:
    // BFS
    // Exp: https://discuss.leetcode.com/topic/13873/two-ac-solution-in-java-using-bfs-and-dfs-with-explanation
    // Time:	O(n)
    // Space:	O(n)
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> result;
        for (auto &edge: prerequisites) {
            adj[edge.second].push_back(edge.first);
            indegree[edge.first]++;
        }
        for (int i = 0; i < numCourses; i++)
            if (!indegree[i]) {
                q.push(i);
                result.push_back(i);
            }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int child : adj[node]) {
                if (!--indegree[child]) {
                    q.push(child);
                    result.push_back(child);
                }
            }
        }
        return result.size() == numCourses ? result : vector<int>();
    }


    // DFS
    // Exp: https://discuss.leetcode.com/topic/13873/two-ac-solution-in-java-using-bfs-and-dfs-with-explanation
    // Time:	O(n)
    // Space:	O(n)
    vector<int> findOrder1(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        stack<int> stk;
        vector<int> result;
        for (auto &edge: prerequisites)
            adj[edge.second].push_back(edge.first);
        for (int i = 0; i < adj.size(); i++)
            if (!visited[i] && !helper(adj, i, visited, onpath, stk))
                return vector<int>();

        while (!stk.empty()) {
            int node = stk.top();
            result.push_back(node);
            stk.pop();
        }
        return result;
    }

    bool helper(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<bool> &onpath, stack<int> &stk) {
        onpath[node] = visited[node] = true;
        for (int child: adj[node])
            if (onpath[child] || (!visited[child] && !helper(adj, child, visited, onpath, stk)))
                return false;
        stk.push(node);
        return !(onpath[node] = false);
    }
};