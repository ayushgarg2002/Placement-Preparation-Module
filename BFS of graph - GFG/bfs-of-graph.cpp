// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    queue<int> q;
    q.push(0);
    vector<int> vis(V,0);
    vis[0]=1;
    vector<int>vec;
    while(!q.empty())
    {
        int val= q.front();
        q.pop();
        vec.push_back(val);
        for(auto x: adj[val])
        {
            if(vis[x]!=1){
                vis[x]=1;
           // cout<<x<<" ";
            q.push(x);
            }
        }
    }
    return vec;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends