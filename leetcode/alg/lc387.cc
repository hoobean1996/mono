// leetcode 387
// First Unique Character in a String

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> m;
    int ans = -1;
    for (int i = s.length() - 1; i >= 0; i--) {
      m[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++) {
      if (m[s[i]] == 1) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};