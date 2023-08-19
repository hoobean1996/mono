// leetcode 2019
// The Score of Students Solving Math Expression

// 给定一个包含数字，+，* 的表达式
// 作为老师，同学们提交了一份答案，有些同学的答案是对的， 我们给打5分
// 有些同学如果是计算顺序错了，我们给2分，比如 2 + 3 * 6 = 20 如果计算成了 30 的话 就给2分
// 其他情况都给0分
// 我们想知道这些同学的总分是多少
// 首先我们需要计算出所有可能的答案，这个就是利用递归即可
// 另外一方面，我们需要手动计算出正确的答案
// 当我们有正确的答案以后
// 我们就可以处理所有同学的成绩了

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<string, vector<int>> memo;
    
    // 给定一个表达式，求解可能算出来的答案是多少（可以允许算错）
    // 假设这个表达式只有一个数字的话，是只有一个答案的
    // 考虑划分s的第一个数字，如果只有一个数字的话，那么我们就直接返回 {num}
    // 否则的话，我们可以遍历整个表达式，如果遇到一个符号的话，就把
    // 表达式看成两部分，left op right
    // 然后递归的求解
    // 考虑left 和 right都有可能很多答案，所以最和是组合起来才是当前表达式的可能答案
    vector<int> possibleAnswers(string s) {
        // 空表达式，只有唯一的空集
        if (s == "") return {};
        
        if (memo.count(s)) return memo[s];

        // 如果是纯数字，只有一种答案
        int num = 0;
        int index = 0;
        while (index < s.length() && isdigit(s[index])) {
            num = num * 10 + (int)(s[index] - '0');
            index++;
        }

        if (index == s.length()) return { num };

        vector<int> ans;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '*') {
                vector<int> left = possibleAnswers(s.substr(0, i));
                vector<int> right = possibleAnswers(s.substr(i + 1));

                for (int l = 0; l < left.size(); l++) {
                    for (int r = 0; r < right.size(); r++) {
                        switch (s[i]) {
                        case '+': {
                            ans.push_back(left[l] + right[r]);
                            break;
                        }
                        case '*': {
                            ans.push_back(left[l] * right[r]);
                            break;
                        }
                        }
                    }
                }
            }
        }

        memo[s] = ans;
        return ans;
    }

    int eval(string s) {
        int n = s.length();
        stack<int> sk;
        char op = '+';
        int cur = 0;
        int i = 0;
        while(i < s.length()) {
            if (isdigit(s[i])) {
                while(isdigit(s[i]) && i < n) {
                    cur = cur * 10  + (s[i] - '0');
                    i ++;
                }
                i --;
            }

            if (s[i] == '+' || s[i] == '*' || i == s.length() - 1) {
                if (op == '+') sk.push(cur);
                else if (op == '*') {
                    int last = sk.top(); sk.pop();
                    sk.push(last * cur);
                }
                cur = 0;
                op = s[i];
            }
            i ++;
        }
        int sum = 0;
        while(!sk.empty()) {
            sum += sk.top(); sk.pop();
        }
        return sum;
    }

    // 计算的方法有很多中，我们可以转换为后缀表达式，然后直接用栈计算
    // 也可以直接计算
    int scoreOfStudents(string s, vector<int>& answers) {
        vector<int> pa = possibleAnswers(s);
        set<int> possibleAns = set<int>(pa.begin(), pa.end());
        int correctValue = eval(s);
        int ans = 0;
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == correctValue) ans += 5;
            else if (possibleAns.find(answers[i]) != possibleAns.end()) ans += 2;
        }
        return ans;
    }
};