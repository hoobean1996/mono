// Leetcode 126
// Word Ladder II
// 成语接龙 II

#include <bits/stdc++.h>

using namespace std;

// 相比于Word Ladder I, 这道题需要列出所有可行的方案
// 利用构建DAG以后，在backtrack遍历所有的最短路径
// 1. 利用BFS遍历构造出DAG
// 2. 利用DAG进行backtrack
// 这道题是在图上回溯

class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        bfs(beginWord, endWord, copiedWordList);
        currPath = { beginWord };
        backtrack(beginWord, endWord);
        return shortestPaths;
    }

    // findNeighbors 用于遍历整个列表，通过给定的规则确定所有字符串相连的字符串
    // 一种写法是遍历所有的字符串，然后check是否只相差一个字符
    // 这样的写法在字符串很多的情况下效率变低
    // 我们可以利用单词本身，遍历每个字符，尝试替换掉，然后判断是否这个字符串存在，
    vector<string> findNeighbors(string& word, unordered_set<string>& wordList) {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];

            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }

    void backtrack(string& source, string& destination) {
        if (source == destination) {
            shortestPaths.push_back(currPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }

    void bfs(string beginWord, string endWord, unordered_set<string> wordList) {
        queue<string> q;
        q.push(beginWord);

        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;

        while (!q.empty()) {
            vector<string> visited;

            for (int i = q.size() - 1; i >= 0; i--) {
                string currWord = q.front();
                q.pop();

                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word : neighbors) {
                    visited.push_back(word);
                    adjList[currWord].push_back(word);

                    if (isEnqueued.find(word) == isEnqueued.end()) {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }


};