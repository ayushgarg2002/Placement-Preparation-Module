// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k) {
    vector<int> F(n, 1);
    for (int i = 1; i < n; i++)
        F[i] = i * F[i - 1];
    string D = "123456789";
    string R; k--;
    for (int i = 0; i < n; i++) {
        int d = k / F[n - i - 1];
        R.push_back(D[d]);
        D.erase(d, 1);
        k %= F[n - i - 1];
    }
    return R;
}
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends