#include <iostream>

using namespace std;

/**
 * Function-object CLASS
 */
class ClassShorter {
    bool operator() (const string& a, const string& b) {
        return a.size() < b.size();
    }
};

/**
 * Function pointer
 * @param a
 * @param b
 * @return bool
 */
static bool isShorter(const string& a, const string& b) {
    return a.size() < b.size();
}


