class Solution {
public:
  bool flag = true;
    void solve(int src, int par, int col, vector<vector<int>> &adj, vector<int>&vis)
    {
        vis[src] = col;
        for(auto x: adj[src])
        {
            if(vis[x]==-1)
            {
                solve(x, src, 3-col, adj, vis);
            }
            else if(x!=par && vis[x]==col){
            flag = false;
            break;
            }
        }
       
    }

   
    bool isBipartite(vector<vector<int>> &graph) {
        int V = graph.size();
	    vector<int> vis(V, -1);
	    int col =1;
	    flag=true;
    	   for(int i=0;i<V;++i)
        {
            if(vis[i]==-1)
            {
                solve(i,0,1,graph,vis);
            }
        }
         return flag;
    }
};