//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int maxGroupSize(int arr[], int N, int K) {
        // code here
        int A[K]{};
        for (int i=0; i<N; i++)
            A[arr[i]%K]++;
        int res = 0;
        if (A[0]) res++;
        if (K%2 == 0 && A[K/2])
            res++;
        for (int i=1; i<(K+1)/2; i++)
            res += max(A[i], A[K-i]);
        return res;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends