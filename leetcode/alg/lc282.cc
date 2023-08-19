// leetcode 282
// Expressions Add Operators

// 给定一个表达式，只包含一组数字，我们希望在这组数字中间添加 + - * /
// 我们肯定是需要枚举所有可能的方法
// 首先考虑一个Trival Case：只有一个数字的情况下，那么只能是一个数字

// Intuition
// 每个符号都是binary operators, 所以每个符号都需要两个操作符
// As each symbol requires two operands, so we can list all possible positions, and then add the symbol
// and then caculate the expression's sum.
// In this way, the Time Complexity is O(4) to the power of n 
// If we have only  + and -
// then we can use the prev sum +/- with current number, that's all
// But if we introduce the *, it would be wrong, as * has high priority 
// Thus we need to maintain the actual operand before the *
#include <bits/stdc++.h>

using namespace std;

// 首先考虑在每个数字之间添加一个符号
// 枚举切分点，val + - * "express"


// recurse(digits, index, expression)
//  if index == digits.length()
//      if (expression == target) put it to ans
//  else:
//      try NO OP 
//      try * 
//      try +
//      try -
class Solution {
public:
    // 目标值
    long target;
    // 结果数组
    vector<string> ans;

    vector<string> addOperators(string num, int t) {
        int n = num.length();

        target = t;
        ans = vector<string>();

        vector<string> ops; 
        backtrack(num, 0, 0, 0, 0, ops);

        return ans;
    }

    // prev 前一个操作数
    // cur 当前的操作数
    // sum 已经计算的部分结果的值
    void backtrack(string digits, int index, long prev, long cur, long sum, vector<string>& ops) {
        int length = digits.length();
        
        // 终止条件：
        // 如果index已经到了末尾，并且sum == target, 
        // cur == 0 意味着没有未处理的值
        if (index == digits.length()) {
            if (sum == target && cur == 0) {
                string s;
                for(int i=1; i<ops.size(); i++) s += ops[i];
                ans.push_back(s);
            }
            return;
        }
        
        // 计算当前的操作数
        cur = cur * 10 + (digits[index] - '0');
        
        // 在当前位置什么符号都不添加
        // 所以index + 1，其他状态不变
        if (cur > 0) backtrack(digits, index + 1, prev, cur, sum, ops);
        

        // 在当前的位置添加一个 + 
        ops.push_back("+");
        ops.push_back(to_string(cur));
        // 当前的操作数变成了 s + ... 前一个操作数
        // cur = 0 因为需要新的分割数字
        // 把当前的结果累计到sum中 ,  因为是 + 可以直接计算
        backtrack(digits, index + 1, cur, 0, sum + cur, ops);
        ops.pop_back();
        ops.pop_back();
        
        if (ops.size() > 0) {
            vector<string> operations {"-", "*"};
            for(const string& op: operations) {
                ops.push_back(op);
                ops.push_back(to_string(cur));
                switch (op)
                {
                case "-":
                    // 如果添加一个 - 变成了 s - ...
                    // 所以结果变成了 sum - cur 
                    backtrack(digits, index+1, -cur, 0, sum - cur, ops);
                    break;
                
                case "*":
                    // 注意到这里由于我们把 * 之前的数，先当作上一个符号的操作数计算了
                    // 所以导致了我们多计算了
                    // 所以我们就用当前的结果 - prev + (cur * prev) 来修正
                    backtrack(digits, index+1, cur * prev, 0, sum - prev + (cur * prev), ops);
                    break;
                }
                ops.pop_back();
                ops.pop_back();
            }
        }
    }
};  