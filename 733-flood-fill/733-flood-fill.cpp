class Solution {
public:
    
    void solve(vector<vector<int>>& image, int sr, int sc, vector<vector<int>> &vis, int newColor, int x, int y, int oldColor)
    {
        if(sr >=x || sc>= y | sr<0 || sc<0)
            return;
        if(image[sr][sc]!=oldColor )
            return;
        if(vis[sr][sc]) 
            return;
        image[sr][sc]=newColor;
      vis[sr][sc]=1;
           
        solve(image, sr+1, sc, vis, newColor, x,y,oldColor);
        solve(image, sr, sc+1, vis, newColor, x,y,oldColor);
        solve(image, sr-1, sc, vis, newColor, x,y,oldColor);
        solve(image, sr, sc-1, vis, newColor, x,y,oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size();
        int y = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<int>> vis(x, vector<int>(y,0));
        solve(image, sr, sc, vis, newColor,x , y, oldColor);
        return image;
    }
};