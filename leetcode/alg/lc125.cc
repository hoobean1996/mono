// leetcode 125
// Valid Palindrome

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.length() <= 1)
            return true;

        int l = 0;
        int r = s.length() - 1;

        while (l < r)
        {
            while (l < r && (!isalpha(s[l]) && !isdigit(s[l])))
                l++;
            while (l < r && (!isalpha(s[r]) && !isdigit(s[r])))
                r--;

            if (l < r && (tolower(s[l]) != tolower(s[r])))
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};