// leetcode 456
// 132 Pattern

// 单调栈模式
class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    int middle = INT_MIN;
    stack<int> st;
    // 为什么要倒着遍历？
    // 35034
    // 倒序遍历的话栈是 4 3 0
    // 当遇到5的时候，会一直弹出，此时第三个数就确定了
    // 在下一个位置的时候，
    // 原因是这是一个单调递减的栈
    // 当middle被设置好的时候，证明比这个middle大的数已经在栈中了
    // 所以如果当前的数小于middle，那么肯定找到了

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < middle)
        return true;
      while (!st.empty() && nums[i] > st.top()) {
        middle = st.top();
        st.pop();
      }
      st.push(nums[i]);
    }
    return false;
  }
};