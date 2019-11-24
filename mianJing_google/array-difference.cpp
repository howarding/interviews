// 两个array， 算第一个array减去第二个array剩下的部分
// 元素的重复次数要考虑进去。比如：A：[1，2，2，2，3]， B [2， 4] ， 最后回一个[1， 2，2，3]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ArrayDifference {
public:
    // Hashmap
    // Time:    O(m + n)
    // Space:   O(n)  n: b.size()
    vector<int> getArrayDifference(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> dict;
        for (int num: b)
            dict[num]++;
        vector<int> result;
        for (int num: a) {
            if (dict[num]-- > 0) continue;
            result.push_back(num);
        }
        return result;
    }
};


//int main() {
//    ArrayDifference arrayDifference;
//    vector<int> a{1, 2, 2, 2, 3}, b{2, 4};
//    vector<int> result = arrayDifference.getArrayDifference(a, b);
//    for (int num: result)
//        cout << num << "\t";
//}