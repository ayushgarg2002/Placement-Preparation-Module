// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// class Solution {
//   public:
//     vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
//         // code here
//     }
// };
class Solution {
public:
    void solve(int ind, vector<int>ds, set<vector<int>>&ans, vector<int>nums){
        if(ind==nums.size())
        {
            // ans.push_back(nums);
            ans.insert(nums);
            return ;
        }
        
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            solve(ind+1, ds, ans, nums);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> nums ,int n) {
       vector<int> ds;
       set<vector<int>> ans;
        vector<vector<int>>res;
        solve(0, ds, ans, nums);
       for(auto x: ans)
       {
           res.push_back(x);
       }
        return res;
    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends