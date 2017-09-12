//Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//
//Follow up:
//Could you do both operations in O(1) time complexity?
//
//Example:
//
//    LFUCache cache = new LFUCache( 2 /* capacity */ );
//
//    cache.put(1, 1);
//    cache.put(2, 2);
//    cache.get(1);       // returns 1
//    cache.put(3, 3);    // evicts key 2
//    cache.get(2);       // returns -1 (not found)
//    cache.get(3);       // returns 3.
//    cache.put(4, 4);    // evicts key 1.
//    cache.get(1);       // returns -1 (not found)
//    cache.get(3);       // returns 3
//    cache.get(4);       // returns 4

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// 3 Hashmap
// Exp: https://discuss.leetcode.com/topic/69436/concise-c-o-1-solution-using-3-hash-maps-with-explanation
// Time:	O(1)
// Space:	O(n)
class LFUCache {
    int _capacity;
    int num;
    int min_count;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> count_list;
    unordered_map<int, list<int>::iterator> key_iter;

public:
    LFUCache(int capacity) {
        _capacity = capacity;
        num = 0;
    }

    // Time:    O(1)
    // Space:   O(n)
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        count_list[cache[key].second].erase(key_iter[key]);
        cache[key].second++;
        count_list[cache[key].second].push_front(key);
        key_iter[key] = count_list[cache[key].second].begin();

        if (count_list[min_count].size() == 0)
            min_count++;
        return cache[key].first;
    }

    // Time:    O(1)
    // Space:   O(n)
    void put(int key, int value) {
        if (_capacity <= 0) return;
        if (get(key) != -1) {
            cache[key].first = value;
            return;
        }
        if (num++ == _capacity) {
            int key2 = count_list[min_count].back();
            count_list[min_count].pop_back();
            cache.erase(key2);
            key_iter.erase(key2);
            num--;
        }
        min_count = 1;
        cache[key] = {value, 1};
        count_list[1].push_front(key);
        key_iter[key] = count_list[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


//int main() {
//    int capacity = 2;
//    LFUCache obj(capacity);
//    obj.put(1,1);
//    cout << "pass" << endl;
//    obj.put(2,2);
//    cout << "pass" << endl;
//    cout << obj.get(1) << endl;
//    obj.put(3,3);
//    cout << "pass" << endl;
//    cout << obj.get(2) << endl;
//    cout << obj.get(3) << endl;
//    obj.put(4,4);
//    cout << "pass" << endl;
//    cout << obj.get(1) << endl;
//    cout << obj.get(3) << endl;
//    cout << obj.get(4) << endl;
//}