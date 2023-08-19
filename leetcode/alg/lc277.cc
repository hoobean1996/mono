// leetcode 277
// Find the Celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

// 这道题的Celebrity是不认识任何人，其他人都认识他
// 所以我们可以一次循环找到一个candidate
// 然后判断是不是所有人都认识他即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ppl;
    
    bool isCelebrity(int i) {
        for(int j=0; j<ppl; j++) {
            if (j != i) {
                if (knows(i, j) || !knows(j, i)) return false;
            }
        }
        return true;
    }
    
    int findCelebrity(int n) {
        // knows(a, b) -> does A know B
        // A -> B
        ppl = n;
        
        int candidate = 0;
        for(int i=0; i<n; i++) {
            if (knows(candidate, i)) candidate = i;
        }
        
        
        if (isCelebrity(candidate)) return candidate;
        
        return -1;
    }
    
};