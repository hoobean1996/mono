// leetcode 1908
// Game of Nim

class Solution {
public:
  bool nimGame(vector<int> &piles) {
    int a = piles[0];
    for (int i = 1; i < piles.size(); i++) {
      a ^= piles[i];
    }
    return a != 0;
  }
};