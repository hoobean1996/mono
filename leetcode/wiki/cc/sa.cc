int n;
int k;
vector<int> sa;
vector<int> rk;
vector<int> tmp;
vector<int> height;

bool cmp(int i, int j) {
  if (rk[i] != rk[j])
    return rk[i] < rk[j];
  int ri = i + k <= n ? rk[i + k] : -1;
  int rj = j + k <= n ? rk[j + k] : -1;
  return ri < rj;
}

void buildSa(string s) {
  n = s.length();
  sa = vector<int>(n + 1, 0);
  rk = vector<int>(n + 1, 0);
  tmp = vector<int>(n + 1, 0);
  height = vector<int>(n + 1, 0);

  for (int i = 0; i <= n; i++) {
    rk[i] = s[i] - 'a';
    sa[i] = i;
  }

  for (k = 1; k <= n; k *= 2) {
    sort(sa.begin(), sa.end(), cmp);
    tmp[sa[0]] = 0;
    for (int i = 0; i < n; i++)
      tmp[sa[i + 1]] = tmp[sa[i]] + (cmp(sa[i], sa[i + 1]) ? 1 : 0);
    for (int i = 0; i < n; i++)
      rk[i] = tmp[i];
  }

  int p = 0;
  for (int i = 0; i < n; i++) {
    if (p)
      p--;
    int j = sa[rk[i] - 1];
    while (i + p < n && j + p < n && s[i + p] == s[j + p])
      p++;
    height[rk[i]] = p;
  }
}
