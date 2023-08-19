vector<int> manacher(string s) {
  vector<int> d1(s.length(), 0);

  int l = 0;
  int r = -1;

  for (int i = 0; i < s.length(); i++) {
    int k = (i > r) ? 1 : min(s[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
      k++;
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }

  return d1;
}
