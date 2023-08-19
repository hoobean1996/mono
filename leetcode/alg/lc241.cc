// leetcode 241
// Different to Add Parentheses
// 在一个表达式中添加括号的方式

#include <bits/stdc++.h>

using namespace std;

// 考虑任意一个输入的表达式串
// 递归终止条件为 empty || isNumber
// 对于每个符号，都递归的处理左边部分和右边部分，并通过该符号结合起来

class Solution {
public:
    // 考虑递归的解法，考虑一个符号的左侧和右侧
    // 从而组合两侧的结果得到当前的结果
    // diffWaysToCompute 返回的结果是在加入不同的括号以后可能的结果
    // 递归终止条件: input == "" || input == number

    bool isEmpty(string input) {
        return input == "";
    }

    pair<int, bool> isNumber(string input) {
        int num = 0;
        int index = 0;
        while(index < input.length() && isdigit(input[index])) {
            num = 10 * num + (int)(input[index] - '0');
            index ++;
        }

        if (index == input.length()) return {num, true};
        return {-1, false};
    }

    vector<int> diffWaysToCompute(string input) {
        // 递归终止条件
        if (isEmpty(input)) return {};
        pair<int, bool> state = isNumber(input);
        if (state.second) return {state.first};
        
        // 递归处理下去
        vector<int> ans;
        // 其他情况
        for (int i = 0; i < input.length(); i++) {
            if ((input[i] == '+' || input[i] == '-' || input[i] == '*')) {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));

                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        char op = input[i];

                        switch (input[i])
                        {
                        case '+':
                            ans.push_back(left[j] + right[k]);
                            break;
                        case '-':
                            ans.push_back(left[j] - right[k]);
                            break;
                        case '*':
                            ans.push_back(left[j] * right[k]);
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};