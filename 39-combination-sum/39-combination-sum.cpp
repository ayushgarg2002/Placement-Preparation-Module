class Solution {
public:
  
    void solve(int ind, vector<int>ds, vector<vector<int>>&ans, vector<int>candidates, int target )
    {
        if(ind==candidates.size())
        {
            if(target==0)
                ans.push_back(ds);
            return ;
        }
        
        if(target>= candidates[ind])
        {
            ds.push_back(candidates[ind]);
            solve(ind, ds, ans, candidates, target-candidates[ind]);
            ds.pop_back();
        }
        solve(ind+1, ds, ans, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
        vector<int >ds;
        vector<vector<int>>ans;
        solve(0, ds, ans, candidates, target);
        return ans;
    }
};