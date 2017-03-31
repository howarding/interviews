//给两个sparse vector, 求点积。用什么存？ vector of pair. 怎么做，用2Pointers，双指针从头开始扫，index一样就乘起来加到结果去，不然的话increment index小的那个
//FU: 如果两个向量一长一短怎么办？用binary search.
//m*n太大了，m*logn也太大了！m+n可以

#include <iostream>
#include <vector>

using namespace std;

class Solution_svdp {
public:
    // 2Pointers
    // Exp: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=230946&extra=page%3D14%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline
    // Time:    O(m+n)
    // Space:   O(1)
    int dotProduct(vector<vector<int>> a, vector<vector<int>> b) {
        int result = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i][0] == b[j][0])
                result += a[i++][1] * b[j++][1];
            else if (a[i][0] < b[j][0])
                i++;
            else
                j++;
        }
        return result;
    }

    // Binary Search
    // 如果两个向量一长一短怎么办 (m << n)？用binary search
    // Time:    O(m * log(n))
    // Space:   O(1)
    int dotProduct_fu(vector<vector<int>> a, vector<vector<int>> b) {
        int result = 0;
        int left = 0, right = b.size() - 1;
        for (auto &pair : a) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (b[mid][0] == pair[0]) {
                    left = mid;
                    result += pair[1] * b[mid][1];
                    break;
                }
                if (b[mid][0] < pair[0])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            right = b.size() - 1;
        }
        return result;
    }
};