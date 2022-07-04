// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution {
public:
  
    void solve(int ind, vector<int>ds, vector<vector<int>>&ans, vector<int>candidates, int target )
    {
        if(ind==candidates.size())
        {
            if(target==0)
                ans.push_back(ds);
            return ;
        }
        
        if(target>= candidates[ind])
        {
            ds.push_back(candidates[ind]);
            solve(ind, ds, ans, candidates, target-candidates[ind]);
            ds.pop_back(); 
           
        }
        solve(ind+1, ds, ans, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { 
       set<int> ans1(candidates.begin(), candidates.end());
       
      // sort(candidates.begin(), candidates.end());
      candidates.assign(ans1.begin(), ans1.end());
        vector<int >ds;
        vector<vector<int>>ans;
        
        solve(0, ds, ans, candidates, target);
        sort(ans.begin(), ans.end());
      
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
}	  // } Driver Code Ends