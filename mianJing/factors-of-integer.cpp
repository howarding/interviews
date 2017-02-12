//正整数全部因子

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution_m001 {
public:
    vector<int> getFactors(int n) {
        vector<int> result;
        if (n <= 0) return result;
        for (int i = 2; i <= sqrt(n); i++) {
            while (n % i == 0) {
                result.push_back(i);
                n /= i;
            }
        }
        if (n != 1) result.push_back(n);
        return result;
    }
};


//int main() {
//    int num = 361;
//    Solution_m001 sol;
//    vector<int> result(sol.getFactors(num));
//    for (int ele : result)
//        cout << ele << endl;
//}