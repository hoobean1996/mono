// leetcode 722
// Remove Comments

class Solution {
public:
  string ltrim(string line) {
    int i = 0;
    bool validChar = false;
    while(i < line.size() && !validChar) {
      if (line[i] == ' ') {
        i ++;
        continue;
      } else {
        i ++ ;
        validChar = true;
        continue;
      }
    }

    return line.substr(i, line.size() - i);
  }

  vector<string> removeComments(vector<string> &source) {

    for(const string& line: source) {
      if ()
    }
  }
};