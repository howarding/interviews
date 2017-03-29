//The API: int read4(char *buf) reads 4 characters at a time from a file.
//
//The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
//
//By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
//
//Note:
//    The read function may be called multiple times.

#include <iostream>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

// Exp: https://discuss.leetcode.com/topic/7094/a-simple-java-code
// Time:	O(n)
// Space:	O(1)
class Solution_158 {
    int buffCnt = 0;
    int buffPtr = 0;
    char buff[5];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ptr = 0;
        while (ptr < n) {
            if (!buffPtr)
                buffCnt = read4(buff);
            if (!buffCnt) break;
            while (ptr < n && buffPtr < buffCnt)
                buf[ptr++] = buff[buffPtr++];
            if (buffPtr == buffCnt) buffPtr = 0;
        }
        return ptr;
    }
};