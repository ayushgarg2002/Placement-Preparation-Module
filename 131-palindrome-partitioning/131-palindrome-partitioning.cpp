class Solution {
public:
 bool isBool(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
   void solve(int index, string s, vector < string > & path,
    vector < vector < string > > & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isBool(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        solve(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        solve(0, s, ds, ans);
        return ans;
    }
};