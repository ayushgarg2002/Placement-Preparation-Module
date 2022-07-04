class Solution {
public:
    void solve(int ind, vector<int>ds, vector<vector<int>> &ans, vector<int>nums )
    {
        if(ind==nums.size())
        {
            ans.push_back(ds); 
            return ;
        }
        
        ds.push_back(nums[ind]);
        solve(ind+1, ds, ans, nums);
        ds.pop_back();
        solve(ind+1, ds, ans, nums);
       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, ds, ans, nums);
        return ans;
    }
};