vector<int> next(string s) {
  vector<int> pi(s.length(), 0);

  for (int i = 1; i < s.length(); i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }

  return pi;
}