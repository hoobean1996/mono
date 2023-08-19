// leetcode 292
// Nim 游戏

// 初始的时候，有一堆石头
// 先手
// 每次可以选择1-3个石头
// 最后一次选择的是获胜的人

bool canWinNim(int n) {
    return n % 4 != 0;
}