void countSort(vector<int> &nums, int maxValue) {
  // count 下标是value
  // count[value] 是对应的value的个数
  vector<int> count(maxValue);
  for (int i = 0; i < nums.size(); i++) {
    count[nums[i]]++;
  }
  // 需要注意这里是count的size
  // 累加得到每个value的排名
  for (int i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
  }

  vector<int> aux(nums.size());
  // 需要注意这里必须是 --count[nums[i]]
  for (int i = nums.size() - 1; i >= 0; i--) {
    aux[--count[nums[i]]] = nums[i];

    // count[nums[i]] - 1  ===> index
    // count[nums[i]] --;
  }
  for (int i = 0; i < nums.size(); i++) {
    nums[i] = aux[i];
  }
}
