//找出所有色子的可能结果
// 比如三个色子，
//  [[1,1,1],[1,1,2],...[6,6,6]].
// input 就是色子个数，return 所有可能出现的结果

#include <iostream>
#include <vector>

using namespace std;

class DiceCombinations {
public:
    // DFS
    // Time
    vector<vector<int>> getDiceCombinations(int N) {
        vector<vector<int>> result;
        vector<int> path;
        helper(N, 1, path, result);
        return result;
    }

    void helper(int N, int start, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == N) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= 6; i++) {
            path.push_back(i);
            helper(N, i, path, result);
            path.pop_back();
        }
    }
};


//int main() {
//    DiceCombinations diceCombinations;
//    int N = 2;
//    cout << "diceCombinations" << endl;
//    vector<vector<int>> result = diceCombinations.getDiceCombinations(N);
//    cout << result.size() << endl;
//    for (auto&& combination: result) {
//        for (int ele: combination)
//            cout << ele << "\t";
//        cout << endl;
//    }
//}