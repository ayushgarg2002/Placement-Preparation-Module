// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int a, int b, vector<vector<int>> &m, int n, string str,  vector<vector<int>> & vis,vector<string>&ans  )
    {
        if(a==n-1 && b== n-1){
            ans.push_back(str);
            return;
        }
        if(a>=n || b>=n || a<0 || b<0 )
        return;
        if(vis[a][b]==1 || m[a][b]==0)
        return ;
        vis[a][b]=1;
        solve(a+1, b, m, n, str+'D', vis, ans);
        solve(a, b+1, m, n, str+'R', vis, ans);
        solve(a-1, b, m, n, str+'U', vis, ans);        
        solve(a, b-1, m, n, str+'L', vis, ans);
        vis[a][b]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n , vector<int>(n));
        vector<string>ans;
        string str="";
        if(m[0][0]==0 || m[n-1][n-1]==0)
        return ans;
        solve(0,0, m, n, str, vis, ans );
        // so
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