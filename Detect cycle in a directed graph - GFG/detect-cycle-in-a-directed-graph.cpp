// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(int i, int V, vector<int>&vis, vector<int>&chk, vector<int>adj[])
    {
        vis[i]=1;
        chk[i]=1;
        for(auto x: adj[i])
        {
            if(!vis[x])
            {
               
                bool see =solve(x, V, vis, chk, adj);
                if(see== true)
                return true;
            }
            else if(chk[x]==1)
            return true;
        }
        chk[i]=0;
        return false;
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        vector<int>chk(V, 0);
       
        for(int i=0 ;i<V;i++)
        {
            if(!vis[i]){
      bool res = solve(i,V, vis, chk, adj);
      if(res==true)
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