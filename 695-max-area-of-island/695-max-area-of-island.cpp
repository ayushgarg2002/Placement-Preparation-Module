class Solution {
public:
    // bool isvalid(int i, int j, vector<vector<int>>& grid, int n, int m)
    // {
    //     if(i<n && j<m && i>=0 && j>=0 && grid[i][j]==1)
    //         return  true;
    //     return false;
    // }
    int  solve(int i, int j, vector<vector<int>>& grid, int n, int m, int &ans)
    {
        if(i>=n || j>=m || i<0 || j<0) 
            return 0;
        if(grid[i][j]==0)
            return 0;
        ans++;
        grid[i][j]=0;
      
        // if(isvalid(i+1, j, grid, n, m))
        // solve(i+1, j, grid, n, m, ans);
        // if(isvalid(i-1, j, grid, n, m))
        // solve(i-1, j, grid, n, m, ans);
        // if(isvalid(i, j+1, grid, n, m))
        // solve(i, j+1, grid, n, m, ans);
        // if(isvalid(i, j-1, grid, n, m))
        // solve(i, j-1, grid, n, m, ans);
        
        return 1+ solve(i+1, j, grid, n, m, ans)+solve(i-1, j, grid, n, m, ans)+  solve(i, j+1, grid, n, m, ans)+  solve(i, j-1, grid, n, m, ans);
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
                 int ok= solve(i,j, grid, n,m, ans);
                res = max(res, ok);
            }
        }
     }
        return res;        
    }
};