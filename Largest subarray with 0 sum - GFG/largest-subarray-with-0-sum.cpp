//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<int, int> mapi;
        int sum=0, i, j, maxi=0;
        for(i=0; i<n; i++)
        {
            sum+=arr[i];
            
            if(sum==0)
            {
             maxi = i+1;
            }
            
            if(mapi.find(sum)!=mapi.end())
            {
                maxi = max(maxi, i-mapi[sum]);
            }
            else
            mapi[sum] = i;
            
            
        }
        return maxi;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends