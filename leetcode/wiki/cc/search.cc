int search(std::vector<int> &nums, int target) {
  int l = 0;
  int r = nums.size();

  while (l < r) {
    int mid = l + (r - l) / 2;
    int(nums[mid] == target) return mid;
    else if (nums[mid] < target) l = mid + 1;
    else if (nums[mid] > target) r = mid;
  }

  return -1;
}