class Solution {
public:
    bool solve(int start, vector<int>&arr, vector<int>&vis, vector<int>&dp,int n)
    {
        if(arr[start]==0)
            return true;
        if(dp[start]!=-1)
            return dp[start];
        bool left= false;
        bool right= false;
        if(vis[start]==0)
        {
        vis[start]=1;
        if(start-arr[start] >= 0)
        left = solve(start-arr[start], arr, vis ,dp ,n);
        if(start+arr[start] <n)
        right = solve(start+arr[start], arr,vis, dp,n);
        }
        return dp[start] = left or right;
    }
    bool canReach(vector<int>& arr, int start) {
         int n= arr.size();
        vector<int> vis(n, 0);       
        vector<int>dp(n+1, -1);
        return solve(start, arr,vis, dp, n);
    }
};