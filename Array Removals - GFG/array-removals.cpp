//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     int removals1(int arr[], int n, int k)
{
   
  // sort the array
  sort(arr, arr + n);
  int dp[n];
 
  // fill all stated with -1
  // when only one element
  for(int i = 0; i < n; i++)
    dp[i] = -1;
 
  // as dp[0] = 0 (base case) so min
  // no of elements to be removed are
  // n-1 elements
  int ans = n - 1;
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    dp[i] = i;
    int j = dp[i - 1];
    while (j != i && arr[i] - arr[j] > k)
    {
      j++;
    }
    dp[i] = min(dp[i], j);
    ans = min(ans, (n - (i - j + 1)));
  }
  return ans;
}
    
    int removals(vector<int>& arr, int k){
        int ans[arr.size()];
        int n=arr.size();
        for(int i=0; i<arr.size(); i++) ans[i]=arr[i];
        return removals1(ans,n,k);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends