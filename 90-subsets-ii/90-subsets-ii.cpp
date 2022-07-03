class Solution {
public:
    void solve(vector<int>&nums, vector<int>&vec, vector<vector<int>>&ans, int ind ,int n)
    {
        ans.push_back(vec);    
                for(int i=ind;i<nums.size();i++)
        {
             if((i!=ind) && nums[i]==nums[i-1])  
                 continue;
            vec.push_back(nums[i]);
            solve(nums, vec, ans, i+1, n) ;
            vec.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        solve(nums, vec, ans, 0, n );
        return ans;
    }
};