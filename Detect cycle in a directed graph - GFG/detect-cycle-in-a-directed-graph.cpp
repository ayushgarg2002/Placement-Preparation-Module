// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // bool isCyclic(int V, vector<int> adj[]) {
    //     // code here
    // }
    bool solve(int src, int V, vector<int>&vis, vector<int>&chk, vector<int>adj[])
    {
        
        vis[src]=1;
        chk[src]=1;
        for(auto x: adj[src])
        {
            if(!vis[x]){
                if(solve(x, V, vis, chk, adj))
                return true;
            }
                else if(vis[x] && chk[x]==1)
                return true;
                
        }
        chk[src]=0;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        vector<int> chk(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(solve(i, V, vis, chk, adj))
                return true;
            }
        }
        return false;
        
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends