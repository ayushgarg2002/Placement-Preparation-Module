class Solution {
public:
    void solve(int ind, vector<int>ds, vector<vector<int>>&ans, vector<int>nums){
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            solve(ind+1, ds, ans, nums);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> ds;
        vector<vector<int>>ans;
        solve(0, ds, ans, nums);
        return ans;
    }
};