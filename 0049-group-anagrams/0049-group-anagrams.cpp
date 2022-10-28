class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        unordered_map<string, vector<string>> mapi;
        
        for(int i=0; i<strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            // mapi[str] = strs[i];
            mapi[str].push_back(strs[i]);
        }
        
        for(auto x: mapi){
            vec.push_back(x.second);
        }
        return vec;
    }
};