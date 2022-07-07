class Solution {
public:
    void solve(int ind, vector<int>ds, set<vector<int>>&ans, vector<int>nums){
        if(ind==nums.size())
        {
            // ans.push_back(nums);
            ans.insert(nums);
            return ;
        }
        
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            solve(ind+1, ds, ans, nums);
            swap(nums[i], nums[ind]);
        }
    }
   vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<int> ds;
       set<vector<int>> ans;
        vector<vector<int>>res;
        solve(0, ds, ans, nums);
       for(auto x: ans)
       {
           res.push_back(x);
       }
        return res;
    }
};