//给一个prime数组，print出所有unique的product，比如[3, 5] -> 3, 5, 15
//follow up 如果有duplicate怎么办

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution_pp {
public:
    vector<int> primeProduct(vector<int> nums) {
        vector<int> result;
        if (nums.empty()) return result;
        int product = 1;
        helper(nums, 0, product, result);
        return result;

    }

    void helper(vector<int> &nums, int start, int product, vector<int> &result) {
        if (start == nums.size()) {
            if (product > 1)
                result.push_back(product);
            return;
        }
        helper(nums, start + 1, product * nums[start], result);
//        if (start < nums.size() - 1 || product > 1) //只有当到最后一个数且当前product为1时，下面语句不执行
        helper(nums, start + 1, product, result);
    }
};


int main() {
    Solution_pp sol;
    vector<int> nums({2, 3, 5});
    vector<int> result(sol.primeProduct(nums));
    for (int num : result)
        cout << num << " ";
    cout << endl;
}