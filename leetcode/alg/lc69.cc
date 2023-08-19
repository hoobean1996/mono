// leetcode 69
// Sqrt(x)

class Solution {
public:
  int mySqrt(int x) {
    if (x < 2)
      return x;

    int l = 1;
    int r = x / 2;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      long sum = (long)mid * mid;
      if (sum == x)
        return mid;
      else if (sum > x) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};