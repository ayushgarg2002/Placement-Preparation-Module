// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
     vector<int> vec;
     void solve(int src, int V, vector<int>&vis ,vector<int>adj[] )
     {
        
       // vis[src]=1;
        vec.push_back(src);
        for(auto x: adj[src])
        {
              if(!vis[x])
              {
               vis[x]=1;
                solve(x, V, vis,adj);
              }
        }
     }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      vec.clear();
      vector<int> vis(V,0);
      vis[0]=1;
      solve(0,V, vis, adj);
      return vec;
       
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends