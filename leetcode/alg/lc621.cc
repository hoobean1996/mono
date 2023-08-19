// leetcode 621
// Task Scheduler

// 任务调度问题
// 给定一组任务和一个整数k，不同的字母代表不同的任务，两个相同的任务之间执行的间隔至少要
// 达到k。
// 假设所有任务的执行时间都一样，都是单位时间。
// 我们想知道为了完成所有的任务，我们至少需要多少的时间
// 如果不能执行任何任务的时间，CPU就处于idle状态即可

// 关键点是我们需要找到需要多少的idle时间
// 考虑频率最高的任务，
// A[]A[]
// 我们至少需要这样排列来避免执行A的时候有idle时间，那么考虑吧其他任务插入到
// []代表着等待安排的空闲时间，一共有 slots = (count(A) - 1 ) * n
// 那么考虑安排剩余的任务 availableTasks = tasks.length - count(a)
// 如果空闲时间是足够的，那么我们就不需要额外的时间了
// 如果不够，我们还需要补充一些时间才行
// idle = max(0, slots - availableTask)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 首先遍历整个任务数组，统计不同的任务的数量信息
        // 并且按照出现的频次排序
        vector<int> freq(26, 0);
        for(int i=0; i<tasks.size(); i++) freq[tasks[i]-'A']++;
        sort(freq.begin(), freq.end());

        // 出现频率最大的任务的频率数
        int maxFreq = *max_element(freq.begin(), freq.end());
        // 以最大频率出现的任务的个数
        int maxFreqCount = count(freq.begin(), freq.end(), maxFreq);
        // maxFreq - 1 是每个slot的格子数
        // 照理说一共有n个格子，但是由于我们已经安排了最大频率的那些任务
        // 剩下的就是 (maxFreq - 1) * (n - (maxFreqCount - 1))
        int emptySlots = (maxFreq - 1) * (n + 1 - maxFreqCount);
        int availableTasks = tasks.size() - maxFreq * maxFreqCount;
        // idles是说那些应该用起来的时间没有用起来，所以被浪费了
        // 所以最后的答案才是 idles + tasks.size()

        // A B ...
        // A B ...
        // A B
        // maxFreq = 3
        // maxFreqCount = 2
        // 由于最后一排不可能有全部元素，不然就不是最多
        // 竖着看: maxFreq - 1
        // 横着看: n + 1 - maxFreqCount
        // 所以右上角的 ... 构成的时间都是idles
        // 由于无论如何都要用tasks.size的时间，我们想知道那些idles 里面有没有能够被利用的时间
        // 所以idels = max(0, emptySlots - availablesTask) 因为如果能够全部用起来的话，
        // 最后实际的安排按照之字型即可
        int idles = max(0, emptySlots - availableTasks);
        return idles + tasks.size();
    }
};