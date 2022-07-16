class Solution {
public:

    void solve(int i, int j, vector<vector<int>>& grid, int n, int m, int &ans)
    {
        if(i>=n || j>=m || i<0 || j<0)
            return;
        if(grid[i][j]==0)
            return;
        ans++;
        grid[i][j]=0;

        solve(i+1, j, grid, n, m, ans);
        solve(i-1, j, grid, n, m, ans);
        solve(i, j+1, grid, n, m, ans);
        solve(i, j-1, grid, n, m, ans);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int i,j,n,m;
     n = grid.size();
     m = grid[0].size();
     int res=0;
     for(i=0;i<n;i++)
     {
        for(j=0;j<m;j++)    
        {
            if(grid[i][j]==1){
                int ans=0;
                 solve(i,j, grid, n,m, ans);
                res = max(res, ans);
            }
        }
     }
        return res;        
    }
};