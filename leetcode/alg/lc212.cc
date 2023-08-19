// leetcode 212
// Word Search II

// 相比于单词搜索 I， 这道题是搜索多个字符串
// 给定一个单词矩阵，和一组字符串，我们希望在这个矩阵中找到所有出现在这组字符串中的的字符串

#include <bits/stdc++.h>

using namespace std;

// 基本的思路是利用给定的多个字符串，构造一个Trie树，然后在树上进行回溯
class TrieNode {
public:
    // next数组不容易打错..
    unordered_map<char, TrieNode*> next;
    // 当前节点是否有字符串
    string word;
};

class Solution {
public:
    vector<vector<char>> _board;
    vector<string> _result;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // x, y 是矩阵上的元素
    // p是当前的TrieNode节点的父亲节点，一开始是root
    void backtrack(int x, int y, TrieNode* p) {
        
        char c = _board[x][y];

        TrieNode* cur = p->next[c];
        
        // 终止条件
        // 当前节点是一个字符串
        // 如果该Trie节点是有对应的字符串的，那么我们就可以把它加入到结果中
        if (cur->word != "") {
            _result.push_back(cur->word);
            // 为了避免重复添加，把word删除
            cur->word = "";
        }
        
        _board[x][y] = '#';
        
        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx < 0 || ny < 0 || nx >= _board.size() || ny >= _board[0].size()) continue;
            // 在递归之前就必须要保证它存在
            if (cur->next.count(_board[nx][ny])) backtrack(nx, ny, cur);
        }
        
        _board[x][y] = c;
        // 如果当前Trie节点没有后续节点，把这个节点也删除
        if (cur->next.empty()) p->next.erase(c);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // 首先利用待搜索的字符构造一颗Trie
        for(const string word: words) {
            TrieNode* node = root;
            
            for(const char c: word) {
                // 使用count(c) 比 find 要简单一些
                if (node->next.count(c)) node = node->next[c];
                else {
                    TrieNode* n = new TrieNode();
                    node->next[c] = n;
                    node = n;
                }
            }
            
            node->word = word;
        }
        
        _board = board;
        
        // 然后利用root节点在树上回溯
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if (root->next.count(_board[i][j])) backtrack(i, j, root);
            }
        }
        
        return _result;
    }
    
    
};