//1. 需要implement class with setWeight + getNextRandom interface，还有自己考虑test case有哪些 (e.g. weight <= 0)
//2. 让你设计一个数据结构，有两个函数 add， fetch。add把 一个object加入其中，然后这个object有权重，fetch要从这个数据结构中随机的取出一个object，这个object选取的概率等于其权重在整个权重和中的比例，比如加入3， 权重=2， 加入5， 权重=1， 加入6 权重=1，那么3的概率就为50%，（2/4）5和6的概率就为25% （1/4)
//3. get an object randomly based on the probability
//4. 给一个object with weights, 然后设计两个函数 put(object, weight), get(). 其中get要返回对应object, 而且是要按照weights等概率的返回.
//5. /**
//* Design a data structure to hold objects with a corresponding integer weight. It should support:
//
//  Obtain an object randomly with probability equal to (weight of the element) / (sum of the weights).
//  Set an object-weight pair. If the object is already in the structure, its weight will be updated. Otherwise, the object will be inserted and set to its weight. If the weight is zero, the object can be removed
//put("A",3)      3/33
//put("B",30)  30/33
//*
//*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Many put
// Few get
// faster put
class weightedSampler1 {
    map<string, int> dict;
    int totalWeight;
public:
    weightedSampler1() : totalWeight(0) {};
    // Time:    O(1)
    // Space:   O(n)
    void put(const string key, int weight) {
        totalWeight += weight - dict[key];
//        dict
    }

    // Time:    O(n)
    // Space:   O(1)
    string get() {
        int num = rand() % totalWeight + 1;
        map<string, int>::iterator iter = dict.begin();
        while (num > 0)
            num -= (iter++)->second;
        return iter->first;

    }

    // Time:    O(1)
    void remove(const string key) {
        if (!dict.count(key)) return;
        totalWeight -= dict[key];
        dict[key] = 0;
    }
};



// Few put
// Many get
// faster get
class weightedSampler {
    map<string, int> dict;
    vector<int> cumWeights;
    vector<string> keys;
//    map<string, FnPtr>
public:
    // Time:    O(n)
    // Space:   O(n) * 3
    void put(const string key, int weight) {
        if (!dict.count(key)) {
            cumWeights.push_back(
                    cumWeights.empty()
                    ? weight
                    : weight + cumWeights.back()
            );
            dict[key] = weight;
            keys.push_back(key);
        } else
            for (int i = 0, found = 0; i < keys.size(); i++)
                if (keys[i] == key || found) {
                    found = 1;
                    cumWeights[i] += weight - dict[key];
                }
    }

    // Binary Search
    // Time:    O(log(n))
    // Space:   O(1)
    string get() {
        int num = rand() % cumWeights.back() + 1;
        // Binary Search
        int left = 0, right = cumWeights.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (num == cumWeights[mid]) return keys[mid];
            if (num > cumWeights[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return keys[left];
    }
};



// Many put
// Few get
// faster put
class weightedSampler2 {
    map<string, int> dict;
    int totalWeight;
public:
    weightedSampler2() : totalWeight(0) {};
    // Time:    O(1)
    // Space:   O(n)
    void put(const string key, int weight) {
        totalWeight += weight - dict[key];
    }

    // Time:    O(log(n))
    // Space:   O(n)
    string get() {
        vector<string> keys;
        vector<int> cumWeights;
        for (auto& pair : dict) {
            if (!pair.second) continue;
            keys.push_back(pair.first);
            cumWeights.push_back(
                    cumWeights.empty()
                    ? pair.second
                    : pair.second + cumWeights.back());
        }

        int num = rand() % cumWeights.back() + 1;
        // Binary Search
        int left = 0, right = cumWeights.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (num == cumWeights[mid]) return keys[mid];
            if (num > cumWeights[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return keys[left];
    }

    // Time:    O(1)
    void remove(const string& key) {
        if (!dict.count(key)) return;
        totalWeight -= dict[key];
        dict[key] = 0;
    }
};