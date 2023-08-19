// leetcode 302
// Smallest Rectangle Enclosing Black Pixels

// 包含黑色砖块的矩形面积
// 将二维的黑色方格区域投影到x轴和y轴
// 看成| | | | ... 
// 一列一列的数组，利用二分法
// 那么原来的check(nums[mid])就自然而然变成check一列

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 将二维的黑色方格区域投影到x轴和y轴
    // 返回的是最左边的i
    int searchCols(vector<vector<char>>& image, int i, int j, int top, int bottom, bool whiteToBlack) {
        while (i != j) {
            // 二分法判断当前的mid是否满足至少有一个1的条件
            int mid = i + (j - i) / 2;

            int k = top;
            // 从上往下走，如果全是0的话，就k++
            // 如果第k行第mid列是0的话， k++
            while (k < bottom && image[k][mid] == '0') k++;

            // 如果k < bottom 那么意味着肯定有1的
            // 往左侧区间继续搜索
            if (k < bottom == whiteToBlack) j = mid;
            // 否则的话
            // 往右侧区间继续搜索
            else i = mid + 1;
        }
        return i;
    }

    int searchRows(vector<vector<char>>& image, int i, int j, int left, int right, bool whiteToBlack) {
        while (i != j) {
            int k = left, mid = i + (j - i) / 2;
            while (k < right && image[mid][k] == '0') k++;
            if (k < right == whiteToBlack) j = mid;
            else i = mid + 1;
        }
        return i;
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        // 搜索区间是 [0, y)
        int left = searchCols(image, 0, y, 0, m, true);

        // 搜索区间是 [y+1, n)
        int right = searchCols(image, y + 1, n, 0, m, false);
        // 搜索区间是 [0, x)
        int top = searchRows(image, 0, x, left, right, true);
        // 搜索区间是 [x+1, m)
        int bottom = searchRows(image, x + 1, m, left, right, false);
        return (right - left) * (bottom - top);
    }
};