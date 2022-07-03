// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
      void solve(vector<int>&nums, vector<int>&vec, vector<vector<int>>&ans, int ind ,int n)
    {
        ans.push_back(vec);    
                for(int i=ind;i<nums.size();i++)
        {
             if((i!=ind) && nums[i]==nums[i-1])  
                 continue;
            vec.push_back(nums[i]);
            solve(nums, vec, ans, i+1, n) ;
            vec.pop_back();
            
        }
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> nums, int n)
    {
            
        vector<int>vec;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        solve(nums, vec, ans, 0, n );
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends