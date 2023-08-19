// leetcode 149
// Max Points on a Line

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int ans = 0;

    for (int i = 0; i < points.size(); i++) {
      map<pair<int, int>, int> m;
      int dup = 1;
      for (int j = i + 1; j < points.size(); j++) {
        if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
          dup++;
          continue;
        }

        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][0];

        int d = gcd(dx, dy);
        m[{dx / dx, dy / d}]++;
        `
      }

      ans = max(ans, dup);
      for (auto it = m.begin(); it != m.end(); it++) {
        ans = max(ans, it->second + dup);
      }
    }

    return ans;
  }

  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
};