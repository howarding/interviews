//A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
//
//Each LED represents a zero or one, with the least significant bit on the right.
//
//
//For example, the above binary watch reads "3:25".
//
//Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
//Example:
//
//    Input: n = 1
//    Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//Note:
//    The order of output does not matter.
//    The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
//    The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution_401 {
public:
    // Backtracking
    // Time:
    // Space:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> path;
        combinations(10, num, 0, 0, path, result);
        return result;
    }

    void combinations(int n, int k, int start, int num, vector<int> &path, vector<string> &result) {
        if (num == k) {
            int hours = 0, minutes = 0;
            for (int ele : path) {
                if (ele < 6)
                    minutes += pow(2, ele);
                else
                    hours += pow(2, ele - 6);
            }
            if (hours < 12 && minutes < 60) {
                string time = to_string(hours) + ':' + (minutes < 10 ? '0' + to_string(minutes) : to_string(minutes));
                result.push_back(time);
            }
            return;

        }
        for (int i = start; i < n; i++) {
            path.push_back(i);
            combinations(n, k, i + 1, num + 1, path, result);
            path.pop_back();
        }
    }


    // Exp: https://discuss.leetcode.com/topic/59401/straight-forward-6-line-c-solution-no-need-to-explain
    // Time:
    // Space:
    vector<string> readBinaryWatch_1(int num) {
        vector<string> rs;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (bitset<10>(h << 6 | m).count() == num)
                    rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        return rs;
    }
};