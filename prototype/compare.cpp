#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// 1. Function-object CLASS
struct Cmp_less {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    }
};

struct Cmp_greater {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    }
};

class Cmp_less1 {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    }
};

class Cmp_greater1 {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    }
};


// 2. Function pointer
static bool compare_less(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

static bool compare_greater(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}


class Heaps {

    vector<pair<string, int>> result;

public:
    void sort_result() {

        // Sort
        // Function pointer
        // Ascending order
        sort(result.begin(), result.end(), compare_less);
        // Descending order
        sort(result.begin(), result.end(), compare_greater);

        // Function object
        Cmp_less cmp_less;
        Cmp_greater cmp_greater;

        // sort: https://en.cppreference.com/w/cpp/algorithm/sort
        sort(result.begin(), result.end(), cmp_less);
        sort(result.begin(), result.end(), cmp_greater);



        // heaps
        // Function-object CLASS
        priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_less> max_heap;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_greater> min_heap;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_less1> max_heap1;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_greater1> min_heap1;

        // priority_queue: https://en.cppreference.com/w/cpp/container/priority_queue
        priority_queue<int> max_heap_int;
        priority_queue<int, vector<int>, less<int>> max_heap_int1;
        priority_queue<int, vector<int>, less<vector<int>::value_type>> max_heap_int2;
        priority_queue<int, vector<int>, greater<int>> min_heap_int;
    }
};


//int main() {
//    Heaps heaps;
//    vector<pair<string, int>> points({{"a", 1},
//                                      {"b", 0},
//                                      {"e", 0},
//                                      {"c", 2},
//                                      {"d", -1}});
//
//    sort(points.begin(), points.end(), compare_less);
//    sort(points.begin(), points.end(), compare_greater);
//
//    // Function object
//    Cmp_less cmp_less;
//    Cmp_greater cmp_greater;
//    sort(points.begin(), points.end(), cmp_less);
//    sort(points.begin(), points.end(), cmp_greater);
//
//

//    // heaps
//    priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_less> max_heap;
//    priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_greater> min_heap;
//    priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_less1> max_heap1;
//    priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp_greater1> min_heap1;
//
//}