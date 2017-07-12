//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//Here is an example of version numbers ordering:
//
//    0.1 < 1.1 < 1.2 < 13.37

#include <iostream>

using namespace std;

class Solution_165 {
public:
    // My own
    // Time:	O(m+n)
    // Space:	O(1)
    int compareVersion(string version1, string version2) {
        int start1(0), start2(0);
        while (start1 < version1.size() || start2 < version2.size()) {
            int end1 = start1, end2 = start2;
            while (end1 < version1.size() && version1[end1] != '.') end1++;
            while (end2 < version2.size() && version2[end2] != '.') end2++;
            int num1 = end1 == start1 ? 0 : stoi(version1.substr(start1, end1-start1));
            int num2 = end2 == start2 ? 0 : stoi(version2.substr(start2, end2-start2));
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            start1 = end1 + 1;
            start2 = end2 + 1;
        }
        return 0;
    }
};


//int main() {
//    Solution_165 sol;
//    string version1("1"), version2("1.1");
//    cout << sol.compareVersion(version1, version2) << endl;
//}