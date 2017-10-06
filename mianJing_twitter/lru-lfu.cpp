//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

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
        if (dict.find(key) != dict.end())
            cache.erase(dict[key]);
        else if (dict.size() == _capacity) {
            dict.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        dict[key] = cache.begin();
    }
};



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