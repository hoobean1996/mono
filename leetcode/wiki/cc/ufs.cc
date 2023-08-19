class UFS {
  UFS(int n) {
    fa = vector<int>(n);
    for (int i = 0; i < n; i++) {
      fa[i] = i;
    }
  }

  int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }

  bool merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
      fa[b] = a;
      return true;
    }
    return false;
  }

private:
  vector<int> fa;
};

class UFSWeighted {
  UFSWeighted() {
    for (int i = 0; i < n; i++) {
      fa[i] = make_pair(i, 1);
    }

    int find(int x) {
      if (x != fa[x].first) {
        int t = fa[x].first;
        fa[x].first = find(fa[x].first);
        fa[x].second *= fa[t].second;
      }
    }

    bool merge(int e1, int e2, double weight) {
      int f1 = find(e1);
      int f2 = find(e2);
      if (f1 != f2) {
        fa[f2].first = f1;
        fa[f2].second = fa[e1].second * weight / fa[e2].second;
      }
    }
  }

private:
  map<int, pair<int, double>> fa;
};