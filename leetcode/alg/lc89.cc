// leetcode 89
// Gray Code
// 格雷码的生成算法

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        
        ans.push_back(0);
        
        while(n --) {
            int m = ans.size();
            
            // 初始情况只有一个0
            // 0
            // 然后倒序遍历这个数组，
            //  1. 左移当前操作的数
            //  2. 添加一个衍生的数
            for(int i=m-1; i>=0; i--) {
                ans[i] = ans[i] << 1;
                ans.push_back(ans[i] + 1);
            }
        }
        
        return ans;
    }
};