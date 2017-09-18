//Given n processes, each process has a unique PID (process id) and its PPID (parent process id).
//
//Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.
//
//We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.
//
//Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.
//
//Example 1:
//    Input:
//    pid =  [1, 3, 10, 5]
//    ppid = [3, 0, 5, 3]
//    kill = 5
//    Output: [5,10]
//    Explanation:
//       3
//     /   \
//    1     5
//         /
//        10
//    Kill 5 will also kill 10.
//Note:
//    1. The given kill id is guaranteed to be one of the given PIDs.
//    2. n >= 1.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution_582 {
public:
    // BFS
    // Exp: https://discuss.leetcode.com/topic/89293/c-clean-code-2-solution-dfs-bfs
    // Time:	O(n)
    // Space:	O(1)
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        unordered_map<int, vector<int>> dict;
        for (int i = 0; i < pid.size(); i++)
            dict[ppid[i]].push_back(pid[i]);
        queue<int> que;
        que.push(kill);
        while (!que.empty()) {
            int num = que.size();
            while (num-- > 0) {
                int id = que.front();
                result.push_back(id);
                que.pop();
                if (dict.find(id) == dict.end()) continue;
                for (int child : dict[id]) que.push(child);
            }
        }
        return result;
    }
};