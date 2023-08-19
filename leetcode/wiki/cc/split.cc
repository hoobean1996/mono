
// split 函数
vector<string> split(string s, string delim) {
  int lastIndex = 0;
  int index;

  vector<string> ans;
  while ((index = s.find(delim, lastIndex) != string::npos)) {
    ans.push_back(s.substr(lastIndex, index - lastIndex));
    lastIndex = index + delim.length();
  }

  if (lastIndex != s.length()) {
    ans.push_back(s.substr(lastIndex, s.length() - lastIndex));
  }

  return ans;
}
