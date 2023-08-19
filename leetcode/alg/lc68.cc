// leetcode 68
// Text Justification

// 给定一些单词列表和一个最大宽度，我们希望把他们进行排版
// 使得每行不超过最大宽度
/*
输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
"This is an",
"example of text",
"justification. "
]
*/
class Solution {
    public:
    void join(vector<string>& v, char c, string& s) {
        s.clear();

        for(vector<string>::iterator p = v.begin(); p != v.end(); p++) {
            s += *p;
            if (p != v.end() - 1) s += c;
        }
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();

        vector<int> lens;
        for(string& word: words) lens.push_back(word.size());
        int l = 0;

        vector<string> ans;
        while(l < n) {
            partLen = lens[l];
            r = l + 1;
            while(r < n and partLen + lens[r] + 1 <= maxWidth) {
                partLen += lens[r] + 1;
                r ++;
            }
            if (r == n) {
                string part;
                join(vector<string>(words.begin()+l, words.begin()+l+r), ' ', part);
            }
        }
    }      
};