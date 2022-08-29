class Solution {
public:
  
    int solve(int i, int j, vector<vector<int>>&grid, int n, int m, int &cnt)
    {
        if(i<0 || j<0 || i>=n || j>=m)
        {
            return 0;
        }
        
        if(grid[i][j]==0)
        {
            return 0;
        }
         cnt+=1;
        
        grid[i][j]=0;
        
       
        solve(i+1, j, grid, n, m, cnt);
        solve(i, j+1, grid, n, m, cnt);
        solve(i-1, j, grid,n, m, cnt);
        solve(i, j-1, grid, n, m, cnt);
              
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int i,j,n= grid.size(), m = grid[0].size(), maxi = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                   int val=0;
                    solve(i,j, grid, n,m, val);
                    {
                        maxi = max(maxi, val);
                    }
                }
            }
        }
        return maxi;
    }
};