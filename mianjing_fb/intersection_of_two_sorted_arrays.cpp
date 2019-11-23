//Example: a1: 1, 3, 4, 7, 11, 107    a2: 2, 3, 11, 19 => 3, 11
//Handle duplicates either full intersection (a1: 1, 2, 2, 2, 4 a2: 0, 2, 2, 5 => 2, 2) or unique intersection (a1: 1,
// 2, 2, 2, 4 a2: 0, 2, 2, 5 => 2)

#include <vector>
#include <cmath>

using namespace std;

class Intersection {
public:
    // Linear Scan  duplicates
    // Time:    O(m + n)
    // Space:   O(1)
    void intersection_ls(vector<int>& a, vector<int>& b, vector<int>& out) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                out.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j])
                i++;
            else
                j++;
        }
    }

    // Linear Scan  unique
    // Time:    O(m + n)
    // Space:   O(1)
    void intersection_ls_unique(vector<int>& a, vector<int>& b, vector<int>& out) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                if (!out.empty() && a[i] != out.back())
                    out.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j])
                i++;
            else
                j++;
        }
    }

    // Binary Search    unique
    // Time:    O(m*log(n))     m << n
    // Space:   O(1)
    void intersection_bs(vector<int>& a, vector<int>& b, vector<int>& out) {
        if (a.size() > b.size()) {
            intersection_bs(b, a, out);
            return;
        }
        int left = 0, right = b.size() - 1;
        for (int num: a) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (b[mid] == num) {
                    out.push_back(num);
                    left = mid + 1;
                    break;
                }
                if (b[mid] < num)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            right = b.size() - 1;
        }
    }

    // BS Smart
    // Ex.2:    a.size() ~ b.size()
    //  a: 1, ..., 100,      200, ..., 300,      400      size: 202
    //  b: 1,      100, ..., 200,      300, ..., 400      size: 202
    //  Number of comparisons:
    //      LS: O(m+n) = 400
    //      BS: O(m*log(n)) = 200 * log(200) = 1.5K
    //      BS_smart: 4 * log(200) = 30     BEST
    void intersection_ls_modified(vector<int>& a, vector<int>& b, vector<int>& out) {
        int i = 0, j = 0, c1 = 0, c2 = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                out.push_back(a[i]);
                i++;
                j++;
                c1 = c2 = 0;
            } else if (a[i] < b[j]) {   // hitting v1 again and again.... v1 is "dense"
                i++;
                c1++;
                c2 = 0;
            } else {                    // hitting v2 again and again.... v2 is "dense"
                j++;
                c1 = 0;
                c2++;
            }

            // Binary search
            if (c1 > log(a.size()))
                i = lower_bound(a.begin() + i, a.end(), b[j]) - a.begin();
            else if (c2 > log(b.size()))
                j = lower_bound(b.begin() + j, b.end(), a[i]) - b.begin();
        }
    }

    void intersection_ls_bs(vector<int>& a, vector<int>& b, vector<int>& out) {
        int i = 0, j = 0, c1 = 0, c2 = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                out.push_back(a[i]);
                c1 = ++i;
                c2 = ++j;
            } else if (a[i] < b[j]) {
                if (i == c1) {  // checkpoint
                    int jump = max(i + log(a.size() - i), a.size() - 1.0);    // test the future at the checkpoint
                    if (a[jump] < b[j])
                        i = c1 = jump;
                    else
                        i++;
                } else
                    i++;
            } else {

            }
        }
    }
};

// Ex.1:    a.size() ~ b.size()
//  a: 1, 3, 5, 7, ..., 1M + 1
//  b: 2, 4, 6, 8, ..., 1M
//  Number of comparisons:
//      LS: O(m+n) = 1M
//      BS: O(m*log(n)) = 500K * log(500K) = 9.5M
// Use intersection_ls

// Ex.2:    a.size() ~ b.size()
//  a: 1, ..., 100,      200, ..., 300,      400      size: 202
//  b: 1,      100, ..., 200,      300, ..., 400      size: 202
//  Number of comparisons:
//      LS: O(m+n) = 400
//      BS: O(m*log(n)) = 200 * log(200) = 1.5K
//      BS_smart: 4 * log(200) = 30
//  Use intersection_ls_modified