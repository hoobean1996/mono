// leetcode 346
// Moving Average from Data Stream

// 我们希望知道数据流中的平均数
// 给定一个数据流，和一个窗口大小，我们希望计算这个滑动窗口的平均值。
// 整体的思路是利用循环队列来实现，该循环队列就是给定的窗口大小。
// 并统计该窗口的和，当新来一个数据的时候，我们减去第一个元素的值，并加上最后一个元素的值，
// 就能在O(1)的时间计算平均值
#include <bits/stdc++.h>

using namespace std;

class MovingAverage {
public:
    // _size 是窗口大小
    int _size = 0;
    // count 是实际元素的个数，因为在没有那么多元素的时候
    // 平均数就不能用_size来计算
    // 所以平均数的除数是 min(_size, count)
    int count = 0;

    int head = 0;
    int sum = 0;
    vector<int> q;
    
    // int size 是窗口大小
    MovingAverage(int size) {
         _size = size; 
        q = vector<int>(_size, 0);
    }
    
    double next(int val) {
        // 当来一个新元素的时候，count ++
        ++ count;
        // 计算尾巴是 head + 1 % _size
        // 找到尾巴以后，需要更新windowSum
        int tail = (head + 1) % _size;
        sum = sum - q[tail] + val;

        // 后面在放置最新的元素，因为可能覆盖掉之前的元素
        head = (head + 1) % _size;
        q[head] = val;
            
        return sum * 1.0 / min(_size, count);
    }
};
