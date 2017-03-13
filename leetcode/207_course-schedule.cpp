//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
//For example:
//
//    2, [[1,0]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
//
//    2, [[1,0],[0,1]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
//
//Note:
//    1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
//    2. You may assume that there are no duplicate edges in the input prerequisites.
//click to show more hints.
//
//Hints:
//    1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
//    2. Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
//    3. Topological sort could also be done via BFS.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_207 {
public:
    // BFS
    // Exp: https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions
    // Time:	O(n)
    // Space:	O(n)
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for (auto &edge: prerequisites) {
            adj[edge.second].push_back(edge.first);
            indegree[edge.first]++;
        }
        int count = 0;
        for (int i = 0; i < numCourses; i++)
            if (!indegree[i])
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int child : adj[node]) {
                if (!--indegree[child])
                    q.push(child);
            }
        }
        return count == numCourses;
    }


    // DFS
    // Exp: https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions
    // Time:	O(n)
    // Space:	O(n)
    bool canFinish1(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        for (auto &edge: prerequisites)
            adj[edge.second].push_back(edge.first);
        for (int i = 0; i < adj.size(); i++)
            if (!visited[i] && !helper(adj, i, visited, onpath))
                return false;
        return true;
    }

    bool helper(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<bool> &onpath) {
        onpath[node] = visited[node] = true;
        for (int child: adj[node])
            if (onpath[child] || (!visited[child] && !helper(adj, child, visited, onpath)))
                return false;
        return !(onpath[node] = false);
    }
};