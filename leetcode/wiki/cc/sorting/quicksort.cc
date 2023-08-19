// int partition(nums, l, r)
// 返回一个下标i, [l..i-1] <= nums[i] <= [i+1..r]
int partition(vector<int> &nums, int l, int r) {
  int x = nums[r];
  int i = l - 1;
  for (int j = l; j <= r; j++) {
    if (nums[j] <= x) {
      swap(nums[++i], nums[j]);
    }
  }
  return i;
}

void quicksort(vector<int> &nums, int l, int r) {
  if (l >= r) {
    return;
  }

  int p = partition(nums, l, r);
  quicksort(nums, l, p - 1);
  quicksort(nums, p + 1, r);
}