//The API: int read4(char *buf) reads 4 characters at a time from a file.
//
//The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
//
//By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
//
//Note:
//The read function will only be called once for each test case.

#include <iostream>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution_157 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    // Exp: https://discuss.leetcode.com/topic/30232/c-concise-solution
    // Time:	O(n/4)
    // Space:	O(1)
    int read(char *buf, int n) {
        int result = 0, m = 0;
        while (n > 0) {
            m = read4(buf);
            result += m;
            buf += m;
            n -= m;
            if (m < 4)
                break;
        }
        if (n < 0)
            result += n;
        return result;
    }
};