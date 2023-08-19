// leetcode 670
// Maxiumum Swap 

// 给定一个整数，我们希望最多交换一次这个数中的两个数位
// 交换过后的这个数，要最大

// 比如：2736，交换以后可以得到的最大值是7236
// 基本的想法是要把后面较大的数往前交换
// 考虑第一位的话，如果后面有更大的数，交换就能得到最大的值
// 如果第一位不能交换的话，那就考虑第二位。。。
// 所以外面一层循环，依次考虑每一位尝试交换就可以

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        // 由于我们要得到最大的值，那么肯定需要把最大的值放在第一位
        // 如果第一位已经是最大的，就考虑第二位
        for(int i=0; i<s.length(); i++) {
            // 考虑当前位
            // 然后在后面循环尝试找到最大的值
            // 必须要 >= 
            // 因为就算是相同的值，也应该选最后面的来进行交换
            int index = i;
            for(int j=i+1; j<s.length(); j++) {
                if (s[j] >= s[index]) index = j;
            }
            // 如果找到了这个最大值的话我们就可以交换了
            // 如果index != i && s[index] != s[i]
            // 当前位不是最大值，就可以交换一次，得到最大值
            // 必须要 s[index] != s[i]
            // 考虑98368 如果没有这句话的话 swap以后也是 98368
            // 但是实际结果是 98836 
            // 原因就是如果当前的index后面有一个较小的值的话，交换以后就能得到一个更大的值
            if (index != i && s[index] != s[i]) {
                swap(s[i], s[index]);
                break;
            }
        }

        return stoi(s);
    }
};