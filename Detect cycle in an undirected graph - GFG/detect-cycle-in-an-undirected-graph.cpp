// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    bool solve(int src, int V, int par, vector<int>&vis, vector<int>adj[])
    {
        queue<int> q;
        q.push(src);
        vis[src]=1;
      
          vector<int> parent(V, -1);
        parent[src] = -1;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            for(auto x: adj[t])
            {
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                    parent[x]=t;
                }
                else if(parent[t]!=x)
                return true;
                
            }
            
            
        }
        return false;
    }
  
    bool isCycle(int V, vector<int> adj[]) {
        
       vector<int>vis(V, 0);
       int par=-1;
       for(int i=0;i<V;i++)
       {
           if(!vis[i]){
               if(solve(i, V, par, vis, adj))
               return true;
           }
           
       }
       return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends