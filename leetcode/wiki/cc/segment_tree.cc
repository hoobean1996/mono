const int n = nums.size();

vector<int> tree(2 * n);

void build(vector<int> &nums) {
  // 愿数组作为叶子节点
  for (int i = n, j = 0; i < 2 * n; i++, j++)
    tree[i] = nums[j];
  for (int i = n - 1; i > 0; i--)
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int pos, int val) {
  pos += n;
  tree[pos] = val;
  while (pos > 0) {
    int l = pos;
    int r = pos;

    if (pos % 2 == 0)
      r = pos + 1;
    else
      l = pos - 1;

    tree[pos / 2] = tree[l] + tree[r];

    pos /= 2;
  }
}

int sumRange(int l, int r) {
  l += n;
  r += n;
  int sum = 0;
  while (l <= r) {
    if ((l % 2) == 1)
      sum += tree[l++];
    if ((r % 2) == 0)
      sum += tree[r--];

    l /= 2;
    r /= 2;
  }

  return sum;
}
