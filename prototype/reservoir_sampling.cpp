//randomly choosing k samples from a list of n items, where n is either a very large or unknown number.

#include <iostream>
#include <vector>

using namespace std;


// Time:    O(n)
// Space:   O(k)
vector<int> selectKItems(vector<int>& stream, int k) {
    vector<int> result;
    int n = 1;
    for (int num: stream) {
        if (n <= k) result.push_back(num);
        else {
            int i = rand() % n;
            if (i < k) result[i] = num;
        }
        n++;
    }
}



int selectOneItem(vector<int>& stream) {
    int result = 0;
    int n = 1;
    for (int num: stream) {
        if (rand() % n++ == 0) result = num;
    }
    return result;
}