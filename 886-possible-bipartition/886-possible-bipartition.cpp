class Solution {
public:
      bool flag = true;
    void solve(int src, int par, int col, vector<int>adj[], vector<int>&vis)
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
    bool possibleBipartition(int n, vector<vector<int>>& graph) {
        vector<int>adj[n];
        for(int i=0; i<graph.size(); i++)
        {
            adj[graph[i][0]-1].push_back(graph[i][1]-1);
            adj[graph[i][1]-1].push_back(graph[i][0]-1);
        }
        int V = n;
	    vector<int> vis(n, -1);
	    int col =1;
	    flag=true;
	    for(int i=0;i<n;++i)
	    {
	    if(vis[i]==-1)
	    {
	        solve(i,0,1,adj,vis);
	    }
	    }
         return flag;
    }
};