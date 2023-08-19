// leetcode 330
// Patching Array

// 给定一个有序数组和一个整数n，对于属于 [1,n] 的任意值
// 我们都希望能够通过数组中的几个元素相加而得到
// 如果不能的话，我们就需要往里面添加多个元素，请问我们需要添加多少
// 考虑当前能够覆盖的最大值 [1, r)
// 如果新的元素<=r，那么是能够覆盖的，并且覆盖的范围可以扩大nums[i]
// 如果新的元素>r，那么采用倍增法来最小话patch的次数
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {   
        // 初始化为0
        int patches = 0;
        
        // index是下标，指向数组中的元素
        int index = 0;

        // maxCover 是当前可达的最大数
        long maxCover = 1;
        
        while (maxCover <= n)
        {   
            // 如果当前的数比 < maxCover，它本来就能被已有的元素拼出来
            // 如果当前的数 = maxCover 它自己就能处理maxCover
            // 但是由于我们有了一个新的数，所以我们能够拼出来的数变大了
            // 考虑任意x in [1, maxCover]
            // 拼凑出x不会用到maxCover + maxCover 
            // 所以结论就是我们的maxCover可以直接加上当前的元素
            if (index < nums.size() && nums[index] <= maxCover)
            {
                maxCover += nums[index++];
            }
            // 否则的话，我们就要尝试patch一个数
            // 这里采用倍增的方法来patch一个数从而减少patch的次数
            // 假设不满足的情况是 [1, r)
            // 多次倍增以后是 [1, 2^i * r) 只需要O(lgn)次就能把当前的值覆盖
            else
            {
                maxCover += maxCover;
                patches++;
            }
        }

        return patches;
    }
};

