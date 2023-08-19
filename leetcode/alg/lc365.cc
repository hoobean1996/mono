// leetcode 365
// Water and Jug Problem 

// 根据裴蜀定理 z = ax + by 有解
// 需要满足 z <= a + b and z | gcd(a, b);
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int val = gcd(jug1Capacity, jug2Capacity);
        if (targetCapacity == 0 || (targetCapacity <= jug1Capacity + jug2Capacity && targetCapacity % val == 0)) return true;
        return false;
    } 
};