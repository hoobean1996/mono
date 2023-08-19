void insertsort(vector<int> &nums) {
  int n = nums.size();
  if (n == 0 || n == 1) {
    return;
  }

  for (int j = 1; j < nums.size(); j++) {
    int key = nums[j];
    int i = j - 1;
    // 从后往前找，找到第一个位置并插入即可
    while (i >= 0 and nums[i] >= key) {
      nums[i + 1] = nums[i];
      i--;
    }
    nums[i + 1] = key;
  }
}