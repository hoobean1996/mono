vector<int> merge(vector<int> &nums, int l, int mid) {
  vector<int> aux;
  int i = l;
  int j = mid + 1;
  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      aux.push_back(nums[i++]);
    } else {
      aux.push_back(nums[j++]);
    }
  }
  while (i <= mid) {
    aux.push_back(nums[i++]);
  }
  while (j <= r) {
    aux.push_back(nums[j++]);
  }
}

void mergesort(vector<int> &nums, int l, int r) {
  if (l >= r) {
    return;
  }

  int mid = l + (r - l) / 2;
  mergesort(nums, l, mid);
  mergesort(nums, mid + 1, r);

  auto aux = merge(nums, l, mid);
  for (int k = 0, p = l; k < aux.size(); k++) {
    nums[p++] = aux[k];
  }
}
