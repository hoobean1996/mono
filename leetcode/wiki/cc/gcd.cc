// int gcd(int, int)
// gcd(a, b) == gcd(b, a)
// gcd(a, b) == gcd(-a, b)
// gcd(a, b) == gcd(|a|, |b|)
// gcd(a, ka) == |a|
// gcd(0, 0) == 0
// gcd(a, 0) == |a|
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// (d, x, y) = egcd(a, b)
int egcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int r = egcd(b, a % b, y, x);
    y -= x * (a / b);
    return r;
  }
}

// 模n有限群(+, *)
// (Z, +): {[a]: 0 <= a <= n-1}
// (Z, *): {[a]: gcd(a, n) = 1}