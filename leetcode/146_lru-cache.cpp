//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//Follow up:
//Could you do both operations in O(1) time complexity?
//
//Example:
//
//    LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//    cache.put(1, 1);
//    cache.put(2, 2);
//    cache.get(1);       // returns 1
//    cache.put(3, 3);    // evicts key 2
//    cache.get(2);       // returns -1 (not found)
//    cache.put(4, 4);    // evicts key 1
//    cache.get(1);       // returns -1 (not found)
//    cache.get(3);       // returns 3
//    cache.get(4);       // returns 4

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// Hash Table + 2 Pointers
// Time:	O(1)
// Space:	O(n)
class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    list<pair<int, int>> cache;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (dict.find(key) == dict.end()) return -1;
        int value = (*dict[key]).second;
        cache.erase(dict[key]);
        cache.push_front({key, value});
        dict[key] = cache.begin();
        return value;
    }

    void put(int key, int value) {
        if (dict.find(key) != dict.end()) cache.erase(dict[key]);
        cache.push_front({key, value});
        dict[key] = cache.begin();
        if (cache.size() > _capacity) {
            dict.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


//int main() {
//    LRUCache cache(1 /* capacity */ );
//    cache.put(2, 1);
//    cout << cache.get(2) << endl;       // returns 1
//    cache.put(3, 2);    // evicts key 2
//    cout << cache.get(2) << endl;       // returns -1 (not found)
//    cout << cache.get(3) << endl;       // returns 3
//}