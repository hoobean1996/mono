
// 素数判定
// 1. 确定性判定 Lucas-Lehmer 测试 椭圆曲线素性证明
// 2. 概率性测试：通过该测试的是 可能素数，通过测试但是实际上不是的是 伪素数
//  - Fermat 素性测试: 不断从[2, n-1]中选取a，并检验是否每次都有 a^(n-1) === 1
//  mod n
bool isPrime(int a) {
  if (a < 2)
    return false;

  for (int i = 2; i * i < a; i++) {
    if (a % i == 0)
      return false;
  }

  return true;
}

// 埃氏筛
void init(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (!isnp[i]) {
      for (int j = i * i; j <= n; j += i)
        isnp[j] = 1;
    }
  }
}

// 欧式筛
void init(int n) {
  for (int i = 2; i <= n; i++) {
    if (!isnp[i])
      primes.push_back(i);
    for (const int p : primes) {
      if (p * i > n)
        break;
      isnp[p * i] = 1;
      if (i % p == 0)
        break;
    }
  }
}