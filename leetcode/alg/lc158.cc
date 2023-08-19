// leetcode 158
// read4 
// 实现readn，可以多次调用

// 如果readPos == writePos
// 证明当前所有的buf都已经读完了
// 所以需要再次调用read4来再读取4个字符
// 如果没有读取到任何字符，那么就应该返回

#include <bits/stdc++.h>

using namespace std;

int read4(char* buf);

class Solution {
public:
    char inbuf[4];
    // readPos代表当前读取的字符位置
    // 如果readPos == writePos 我们就再次调用read4 读取4个字符
    int readPos = 0;
    int writePos = 0;

    int read(char* buf, int n) {
        for (int i = 0; i < n; i++) {
            if (readPos == writePos) {
                writePos = read4(inbuf);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = inbuf[readPos++];
        }

        return n;
    }
};