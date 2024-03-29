//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int n) {
        // code here
           int mod = 100000000;

        int dp[n+1];

        dp[0] = 1;

        dp[1] = 1;

        

        for(int i=2;i<=n;i++)

        {

            dp[i] = ((dp[i-1]%mod)+(dp[i-2]%mod))%mod;

        }

        return dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends