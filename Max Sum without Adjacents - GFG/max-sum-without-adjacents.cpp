// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	    int mini=arr[0],maxi=0,tr;
	    for(int i=1;i<n;i++)
        {
            tr= max(mini,maxi);
            mini= maxi+ arr[i];
            maxi= tr;

        }
        return max(mini, maxi);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends