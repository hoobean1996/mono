// leetcode 636
// Exclusive Time of Functions

// 函数执行的独占时间
// 在一个单核CPU中，我们执行一个包含n个函数的程序
// 每个函数都有唯一的函数ID
// 函数调用被存放在call stack中，当开始执行一个函数的时候，需要把对应函数的函数ID push到栈上
// 当函数执行完成的时候，我们需要把栈上的函数ID pop出来
// 栈顶的函数ID代表的是当前正在执行的函数
// 每当一个函数开始执行或者执行结束的时候，我们就会打印一条log

// 现在的情况是，我们有一些logs，每个log有特定的格式来代表是开始还是结束
// 我们希望统计的是每个函数的总共执行时间信息

// Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
// 一共两个函数
// 分别ID是0和1
// "0:start:0" -> "[function id]:[start | end]:timestamp"

// 基本上利用栈来模拟执行的过程，在弹出的时候统计时间即可

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> split(string s, string delim) {
        vector<string> ans;
        
        int index;
        int lastIndex = 0;
        
        while((index=s.find(delim, lastIndex)) != string::npos) {
            ans.push_back(s.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.length();
        }
        if (lastIndex != s.length()) {
            ans.push_back(s.substr(lastIndex, s.length() - lastIndex));
        }
        return ans;
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> sk;

        int preTimestamp = 0;
        
        sk.push(0);
        
        // 首先我们遍历所有的日志，解析出来具体的信息
        // 对于每个日志的话，我们需要考虑的是
        // 开始日志计算的是当前的栈上的函数，而不是该函数，因为该函数还没有放上去
        // 结束的日志计算的就是栈顶函数

        // 1. 如果是开始的日志的话，那么当前在栈上的函数的运行时间就是
        // ans[sk.top()] += logTimestmap - preTimestamp
        // preTimestamp = logTimestmap
        // sk.push(logID)
        // 并且把新的函数放到栈上
        // 2. 如果是结束的日志的话，那么当前的栈上的函数运行时间就是
        // ans[logID] += logTimestamp - preTimestamp + 1
        for(const string log: logs) {
            // log 的格式
            // [id] [start | end] [time]
            vector<string> v = split(log, ":");

            int logID = stoi(v[0]);
            string logType = v[1];
            int logTimestamp = stoi(v[2]);

            if (logType == "start") {
                // sk.top() 表示当前运行的函数的ID
                // 如果新运行一个函数
                // 那么上一个函数 ans[sk.top()] 的运行时间就是当前的时间戳 - preTimestamp
                ans[sk.top()] += logTimestamp - preTimestamp;
                sk.push(logID);
                preTimestamp = logTimestamp;
            } else {
                // 如果是结束一个函数
                // 当前的运行的函数就是
                // 如果是开始的话，是代表格子开始的时候
                // 如果是结束的话，是代表格子结束的时候
                // 所以logTimestamp ++
                ans[logID] += logTimestamp - preTimestamp + 1;
                sk.pop();
                preTimestamp = logTimestamp + 1;
            }
            
        }
        return ans;
    }
};