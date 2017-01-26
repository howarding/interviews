#include <iostream>

using namespace std;

bool lexicographical_compare(string s1, string s2) {
    // comparator for "<"
    // s1 < s2:     true
    // s1 >= s2:    false
    int len = min(s1.size(), s2.size());
    for (int i = 0; i < len; i++) {
        if (s1[i] < s2[i]) return true;
        if (s1[i] > s2[i]) return false;
    }
    return s1.size() < s2.size();
}