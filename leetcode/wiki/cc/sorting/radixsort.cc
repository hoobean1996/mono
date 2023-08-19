void radixSort(vector<int> &nums) {
  int maxValue = *max_element(nums.begin(), nums.end());
  int n = nums.size();
  int exp = 1;
  int radix = 10;

  vector<int> aux(n);

  while (maxValue / exp > 0) {
    vector<int> count(radix, 0);
    for (int i = 0; i < n; i++) {
      count[(nums[i] / exp) % radix]++;
    }
    for (int i = 1; i < count.size(); i++) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      aux[--count[(nums[i] / exp) % radix]] = nums[i];
    }
    exp *= 10;
  }
  for (int i = 0; i < n; i++) {
    nums[i] = aux[i];
  }
}
