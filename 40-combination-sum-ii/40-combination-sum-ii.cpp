class Solution {
public:
  
    void solve( vector<int>&candidates, int target, int ind, vector<int>&v, vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i= ind; i<candidates.size(); i++)
        {
            if(i!=ind && candidates[i-1]== candidates[i]) 
                continue;
            if(target<candidates[i])
               break;
            v.push_back(candidates[i]);
            solve(candidates, target- candidates[i], i+1, v, ans);
            v.pop_back();
                
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> v;
        vector<vector<int>> ans;
        solve(candidates, target, 0, v, ans);
        
        sort(ans.begin(),ans.end());
             
        
        return ans;
    }
};