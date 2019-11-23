//
// Created by Hao Ding on 10/26/19.
//
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef int Task;
const Task kDummyTask = '_';
struct TaskCount {
    Task task;
    size_t count;
    TaskCount(): task(kDummyTask), count(0) {}
    TaskCount(Task t, size_t c): task(t), count(c) {}
};

struct taskCountCmp {
    bool operator()(const TaskCount& t1, const TaskCount& t2) {
        if (t1.count == t2.count) return t1.task > t2.task;
        return t1.count < t2.count;
    }
};

struct Cmp {
    bool operator()(pair<int, size_t >& a, pair<int, size_t >& b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
};

class TaskScheduler {
public:
    // Heap
    // https://leetcode.com/articles/task-scheduler/
    // Time:    O(m)    m: size of tasks
    // Space:   O(1)
    vector<int> getScheduleTasks(const vector<int>& tasks, int interval) {
        unordered_map<int, size_t> taskCounts;
        for (const int& task: tasks)
            taskCounts[task]++;

        // Build a max-heap for the results, ordered by count
        priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, Cmp> max_heap;
        for (const auto& taskCount: taskCounts)
            max_heap.push(taskCount);

        vector<int> result;
        // int total = 0;       // to get the total count
        while (!max_heap.empty()) {
            int count = 0;
            vector<pair<int, size_t>> tmp;
            while (count <= interval) {
                if (max_heap.empty() && tmp.empty()) break;
                if (!max_heap.empty()) {
                    pair<int, size_t> taskCount = max_heap.top();
                    max_heap.pop();
                    result.push_back(taskCount.first);
                    if (taskCount.second-- > 1) tmp.push_back(taskCount);
                } else
                    result.push_back('_');
                count++;
                // total++;     // to get the total count
            }
            for (pair<int, size_t>& taskCount: tmp)
                max_heap.push(taskCount);
        }
        return result;
    }
};

class task_scheduler_fb {
public:
    vector<Task> scheduleTasks(const vector<Task> tasks, int interval) {
        unordered_map<Task, size_t> counts;
        for (const auto& task: tasks)
            counts[task]++;

        // Build a max-heap for the results, ordered by count
        priority_queue<TaskCount, vector<TaskCount>, taskCountCmp> max_heap;
        for (const auto& pair: counts) {
            TaskCount taskCount(TaskCount(pair.first, pair.second));
            max_heap.push(TaskCount(pair.first, pair.second));
        }

        // Now build up the output, starting with the most frequent tasks first
        vector<Task> result;
        // A circular buffer of tasks waiting on their recovery interval to expire
        vector<TaskCount> recovery;
        recovery.resize(interval + 1);
        int recoveryIdx = 0;
        size_t tasksRun = 0;
        while (tasksRun < tasks.size()) {
            // The item at recovery[recoveryIdx] is ready to run again,
            // and can go back into the heap.
            if (recovery[recoveryIdx].count > 0)
                max_heap.push(recovery[recoveryIdx]);

            // Get the next item to run.
            // Note that if the heap is empty at this point, all tasks are waiting on
            // the recovery period and we have to run a dummy task instead.
            TaskCount taskCount;
            if (!max_heap.empty()) {
                taskCount = max_heap.top();
                max_heap.pop();
                assert(taskCount.count > 0);
                taskCount.count--;
                tasksRun++;
            }
            result.push_back(taskCount.task);
            recovery[recoveryIdx++] = taskCount;
            if (recoveryIdx > interval)
                recoveryIdx = 0;
        }
        return result;
    }
};


//int main() {
//    cout << "hello task." << endl;
//    TaskScheduler taskScheduler;
//    vector<int> tasks{1, 1, 1, 2, 2, 2};
//    int interval = 2;
//    vector<int> result = taskScheduler.getScheduleTasks(tasks, interval);
//    for (int task: result)
//        cout << task << '\t';
//    cout << endl;
//}