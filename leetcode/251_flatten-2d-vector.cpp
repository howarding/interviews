//Implement an iterator to flatten a 2d vector.
//
//For example,
//    Given 2d vector =
//
//    [
//        [1,2],
//        [3],
//        [4,5,6]
//    ]
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
//
//Hint:
//
//    1. How many variables do you need to keep track?
//    2. Two variables is all you need. Try with x and y.
//    3. Beware of empty rows. It could be the first few rows.
//    4. To write correct code, think about the invariant to maintain. What is it?
//    5. The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
//    6. Not sure? Think about how you would implement hasNext(). Which is more complex?
//    7. Common logic in two different places should be refactored into a common method.
//Follow up:
//As an added challenge, try to code it using only iterators in C++ or iterators in Java.

#include <iostream>
#include <vector>

using namespace std;

// Exp: https://discuss.leetcode.com/topic/20697/7-9-lines-added-java-and-c-o-1-space
// Time:	O(1)
// Space:	O(1)
class Vector2D {
    vector<vector<int>>::iterator iter1, end;
    vector<int>::iterator iter2;
public:
    Vector2D(vector<vector<int>> &vec2d) {
        iter1 = vec2d.begin();
        end = vec2d.end();
        if (!vec2d.empty()) iter2 = (*iter1).begin();
    }

    int next() {
        return *iter2++;
    }

    bool hasNext() {
        while (iter1 != end) {
            if (iter2 != (*iter1).end())
                return true;
            iter1++;
            if (iter1 == end)
                return false;
            iter2 = (*iter1).begin();
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */


//int main() {
//    vector<vector<int>> vec2d({{1, 2}, {3}, {4, 5, 6}});
//    Vector2D i(vec2d);
//    while (i.hasNext()) cout << i.next() << endl;
//}