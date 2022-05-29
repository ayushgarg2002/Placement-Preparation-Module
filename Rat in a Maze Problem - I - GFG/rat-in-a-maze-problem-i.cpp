// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void dfs(int a, int b, string s, vector<vector<int>> &m, int n,vector<vector<int>> &vis)
    {
       if(a<0 || a>=n || b<0 || b>=n)  return;
       if(m[a][b]==0 || vis[a][b]==1)  return;
       
       if(a==n-1 && b==n-1)
       {
           ans.push_back(s);
           return;
           
       }
       
        vis[a][b]=1;
        dfs(a+1, b, s+'D', m, n,vis);
        dfs(a-1, b, s+'U', m, n,vis);
        dfs(a, b+1, s+'R', m, n,vis);
        dfs(a, b-1, s+'L', m ,n,vis);
        vis[a][b]=0;
      //  s="";
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ans.clear();
      string s = "";
       if(m[0][0]==0 || m[n-1][n-1]==0){
       // ans.push_back("-1");
        return ans;
        }
       vector<vector<int>> vis(n, vector<int>(n));
       dfs(0,0,s, m, n, vis);
       sort(ans.begin(), ans.end());
       return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends