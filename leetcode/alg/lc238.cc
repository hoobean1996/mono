// leetcode 238
// Product of Array Except Self

// 类似于前缀和
// 我们需要构建左前缀乘积和右后缀乘积
// 通过复用ans数组来节省空间
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        
        ans[0] = 1;
        for(int i=1; i<n; i++) ans[i] = ans[i-1] * nums[i-1];
        
        int R = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] = ans[i] * R;
            R *= nums[i];
        }
        
        return ans;
    }
};