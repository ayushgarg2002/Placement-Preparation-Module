// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        int arr[N];
        vector<int> res;
        arr[N-1]= Arr[N-1];
        for(int i=N-2;i>=0;i--){
            arr[i] = min(arr[i+1], Arr[i]);
        }
        for(int i=0;i<N; i++)
        {
            int low= i+1, hi= N-1, ans=-1;
            while(low<=hi)
            {
                int mid = (low+hi)/2;
                if(arr[mid]<Arr[i])
                {
                    ans = mid;
                    low= mid+1;
                }
                else{
                    hi = mid - 1;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends