//Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
// represent different tasks. Tasks could be done without original order. Each task could be done in one interval.
// For each interval, CPU could finish one task or just be idle.
//
//However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n
// intervals that CPU are doing different tasks or just be idle.
//
//You need to return the least number of intervals the CPU will take to finish all the given tasks.
//
//
//
//Example:
//
//    Input: tasks = ["A","A","A","B","B","B"], n = 2
//    Output: 8
//    Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
//
//
//Note:
//
//    1. The number of tasks is in the range [1, 10000].
//    2. The integer n is in the range [0, 100].

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_621 {
public:
    // BEST: Count idle slots
    // Time:    O(m)    m: size of tasks
    // Space:   O(1)
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26, 0);
        for (const char task: tasks)
            map[task - 'A']++;
        sort(map.begin(), map.end());
        int max_val = map.back() - 1, idle_slots = max_val * n;
        for (int i = 24; i >= 0; i--)
            if (map[i] > 0 && idle_slots > 0)
                idle_slots -= min(map[i], max_val);
        return tasks.size() + max(idle_slots, 0);
    }


    // Heap
    // https://leetcode.com/articles/task-scheduler/
    // Time:    O(m)    m: size of tasks
    // Space:   O(1)
    int leastInterval1(vector<char>& tasks, int n) {
        int result = 0;
        vector<int> map(26, 0);
        for (const char task: tasks)
            map[task - 'A']++;
        priority_queue<int, vector<int>, less<int>> max_heap;
        for (int count: map)
            if (count > 0) max_heap.push(count);
        while (!max_heap.empty()) {
            int count = 0;
            vector<int> tmp;
            while (count <= n) {
                if (max_heap.empty() && tmp.empty()) break;
                if (!max_heap.empty()) {
                    int num = max_heap.top();
                    max_heap.pop();
                    if (--num > 0) tmp.push_back(num);
                }
                result++;
                count++;
            }
            for (int num: tmp) max_heap.push(num);
        }
        return result;
    }


    // Sort
    // https://leetcode.com/articles/task-scheduler/
    // Time:    O(m)    m: size of tasks
    // Space:   O(1)
    int leastInterval2(vector<char>& tasks, int n) {
        int result = 0;
        vector<int> map(26, 0);
        for (const char task: tasks)
            map[task - 'A']++;
        sort(map.begin(), map.end());
        while (map[25] > 0) {
            int count = 0;
            while (count <= n) {
                if (map[25] == 0) break;
                if (count <= 25 && map[25 - count] > 0) {
                    map[25 - count]--;
                }
                result++;
                count++;
            }
            sort(map.begin(), map.end());
        }
        return result;
    }
};

//int main() {
//    Solution_621 sol;
//    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
//    int n = 2;
//    int result = sol.leastInterval(tasks, n);
//    cout << result;
//}