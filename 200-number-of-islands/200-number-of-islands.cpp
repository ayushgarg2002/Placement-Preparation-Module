class Solution {
public:
    void solve(int i,int j, vector<vector<char>>&grid, int n, int m)
    {
        if(i<0 || j<0 || i>=n|| j>=m)
            return;
        
        if(grid[i][j]=='0')
            return;
        
        grid[i][j]='0';
        
        solve(i+1, j, grid, n, m);
        solve(i-1, j, grid, n, m);
        solve(i, j+1, grid, n, m);
        solve(i, j-1, grid, n, m);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid[0].size(),n=grid.size(),i,j, cnt=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(i,j, grid, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};