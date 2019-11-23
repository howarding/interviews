// Given K sorted lists of up to N elements in each list, return a sorted iterator over all the items.
// K << N
// there could be duplicate numbers

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Cmp {
    bool operator()(pair<int, vector<int>::iterator> a, pair<int, vector<int>::iterator> b) {
        return *(a.second) > *(b.second);
    }
};

// Min heap
// Construction Time:   O(k*log(k))
// Next Time:           O(log(k))
// Space:               O(k)
class SortedIterator {
    vector<vector<int>::iterator> ends;
    priority_queue<pair<int, vector<int>::iterator>, vector<pair<int, vector<int>::iterator>>, Cmp> min_heap;
public:
    SortedIterator(vector<vector<int>>& lists) {
        int i = 0;
        for(vector<int>& list: lists) {
            if (!list.empty()) {
                min_heap.push({i++, list.begin()});
                ends.push_back(list.end());
            }
        }
    }

    bool hasNext() {
        return !min_heap.empty();
    }

    vector<int>::iterator next() {
        if (!hasNext())
            throw;
        auto ele = min_heap.top();
        min_heap.pop();
        if (ele.second != ends[ele.first] - 1)
            min_heap.push({ele.first, ele.second + 1});
        return ele.second;
    }
};


//int main() {
//    vector<vector<int>> lists{{1, 4, 5, 8, 9}, {3, 4, 4, 6}, {0, 2, 8}};
//    SortedIterator sortedIterator(lists);
//    while (sortedIterator.hasNext())
//        cout << *sortedIterator.next() << "\t";
//}