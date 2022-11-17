//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	      ll sum=0,i,j,count=0;
	    for(i=0;i<n;i++){
	        if(arr[i]>k){
	           // if(count)
	           sum++;
	           sum+=count+(n-1-i);
	                sum+=(count*(n-1-i));
	           //else sum+=(n-i);
	           count=0;
	        }
	        else count++;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends