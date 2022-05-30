class Solution {
public:
    
   void dfs(vector<vector<int>>& vis ,vector<vector<int>>& image, int sr, int sc, int x, int y, int old, int newColor)
    {
        if(sr<0 || sc<0 || sr>=x || sc>=y)
            return;
        
        if(vis[sr][sc]==1 || image[sr][sc]!= old)
            return;
        image[sr][sc]= newColor;
        vis[sr][sc]=1;
        dfs(vis,image, sr, sc+1, x,y, old, newColor);
        dfs(vis,image, sr, sc-1, x,y,old, newColor);
        dfs(vis,image, sr+1, sc, x,y,old, newColor);
        dfs(vis,image, sr-1, sc, x,y,old, newColor);
        
        //vis[sr][sc]=0;    yaha ye ni krange kyuki yaha hme sare possible path ni dhekne bs ek bbar value change krni h image ki
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int x= image.size();
        int y= image[0].size();
        vector<vector<int>> vis(x, vector<int>(y,0));
        int old= image[sr][sc];
        dfs(vis, image, sr, sc,x,y,old, newColor);
        return image;
    }
};