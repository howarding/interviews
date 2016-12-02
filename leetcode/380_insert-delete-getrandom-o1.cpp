//Design a data structure that supports all following operations in average O(1) time.
//
//insert(val): Inserts an item val to the set if not already present.
//remove(val): Removes an item val from the set if present.
//getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
//Example:
//
//// Init an empty set.
//    RandomizedSet randomSet = new RandomizedSet();
//
//// Inserts 1 to the set. Returns true as 1 was inserted successfully.
//randomSet.insert(1);
//
//// Returns false as 2 does not exist in the set.
//randomSet.remove(2);
//
//// Inserts 2 to the set, returns true. Set now contains [1,2].
//randomSet.insert(2);
//
//// getRandom should return either 1 or 2 randomly.
//randomSet.getRandom();
//
//// Removes 1 from the set, returns true. Set now contains [2].
//randomSet.remove(1);
//
//// 2 was already in the set, so return false.
//randomSet.insert(2);
//
//// Since 1 is the only number in the set, getRandom always return 1.
//randomSet.getRandom();

#include <iostream>
#include <vector>
#include <map>


using namespace std;

class RandomizedSet {
    vector<int> vals;
    map<int, int> val_ind;

public:
    // Exp: https://discuss.leetcode.com/topic/53286/ac-c-solution-unordered_map-vector
    // Time:	O(1)
    // Space:	O(n)
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val_ind.find(val) != val_ind.end())
            return false;
        vals.push_back(val);
        val_ind[val] = vals.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val_ind.find(val) == val_ind.end())
            return false;
        int ind = val_ind[val];
        int last_val = vals.back();
        vals[ind] = last_val;
        val_ind[last_val] = ind;
        vals.pop_back();
        val_ind.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int rand_ind = rand() % vals.size();
        return vals[rand_ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */