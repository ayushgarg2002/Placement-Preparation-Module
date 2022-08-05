// class Solution {
// public:
//     void solve(int pos, int sum, vector<int>&nums, int target, vector<int>&vis, int &times)
//     {
//         if(sum==target || pos == nums.size())
//         {
//             return;
//         }

//              times+=1;
//             // vis[pos]=1;
//         solve(pos, sum+nums[pos], nums, target, vis, times);
//         // times -=1;
//        // vis[pos]=0;
//     }
//     int combinationSum4(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int>vis(n, 0);
//         int sum=0;
//         int times = 0;
//         solve(0, sum, nums, target, vis, times);
//         return times;
//     }
// };

class Solution {
public:
    
    int count = 0;
    unordered_map<int,int> mp;
    //pour dfs will cause TLE, use dp (cached)
    int dfs(vector<int>& nums, int target){
        if(target<0)return 0;
        if(mp.find(target)!=mp.end()) return mp[target];
        if(target==0){
            return 1;
        }
        
        for(int i = 0; i<nums.size(); i++){
            mp[target] += dfs(nums,target-nums[i]);
        }
        return mp[target];
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums,target);
    }
};