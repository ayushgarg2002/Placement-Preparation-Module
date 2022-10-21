//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int row, int col, vector<vector<int>>&a)  {
        // code here
        // int i,j, p=0, q=0;
        // vector<int>vec;
        
        // while(r>p && c>q)
        // {
        //      for(i=p; i<r; i++)
        //      {
        //         for(j=q; j<c; j++)
        //         {
        //             vec.push_back(a[i][j]);
        //         }
        //     }
        //     p=p+1;
        //     q= q-1;
            
        // }
        // return vec;
       
       
       int left = 0;
        int right = col;
        int top = 0;
        int bot = row;
        vector<int> ans;
        while(left < right && top < bot){
            if(left < right && top < bot){
                for(int i=left;i<right;i++){
                    ans.push_back(a[top][i]);
                }
                top++;
            }
            if(left < right && top < bot){
                for(int i=top;i<bot;i++){
                    ans.push_back(a[i][right-1]);
                }
                right--;
            }
            if(left < right && top < bot){
                for(int i=right-1;i>=left;i--){
                    ans.push_back(a[bot-1][i]);
                }
                bot--;
            }
            if(left < right && top < bot){
                for(int i=bot-1;i>=top;i--){
                    ans.push_back(a[i][left]);
                }
                left++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends