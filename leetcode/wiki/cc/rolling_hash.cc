
vector<int> rolling_hash(string s) {
  int m = 1e9 + 7;

  vector<int> f(s.length() + 1, 0);

  for (int l = 1; l <= s.length(); l++) {
    f[l] = f[l - 1] + (s[l - 1] - 'a') * pow(26, l - 1);
  }

  return f;
}
