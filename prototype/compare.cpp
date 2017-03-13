#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class heaps {

    struct cmp_less {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            return a.second < b.second;
        }
    };

    struct cmp_greater {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            return a.second > b.second;
        }
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp_less> max_heap;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp_greater> min_heap;

    vector<pair<string, int>> result;

public:
    static bool compare_less(pair<string, int> a, pair<string, int> b) {
        return a.second < b.second;
    }

    static bool compare_greater(pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    }

    void sort_result() {
        // Ascending order
        sort(result.begin(), result.end(), compare_less);
        // Descending order
        sort(result.begin(), result.end(), compare_greater);
    }
};