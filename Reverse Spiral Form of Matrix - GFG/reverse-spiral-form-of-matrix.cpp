//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int row, int col, vector<vector<int>>&a)  {
       
       int left=0;
       int right=col;
       int top = 0;
       int bot=row;
       vector<int>vec;
       while(left<right && top<bot)
       {
           
           if(left<right && top<bot)
           {
               for(int i=left; i<right; i++)
                {
                    vec.push_back(a[top][i]);
                }
           }
           top++;
           if(left<right && top<bot)
           {
               for(int i=top; i<bot; i++)
                {
                    vec.push_back(a[i][right-1]);
                }
           }
           right--;
           
           if(left<right && top<bot)
           {
               for(int i=right-1; i>=left; i--)
                {
                    vec.push_back(a[bot-1][i]);
                }
           }
           bot--;
           
           if(left<right && top<bot)
           {
               for(int i=bot-1; i>=top; i--)
                {
                    vec.push_back(a[i][left]);
                }
           }
           left++;
       }
       reverse(vec.begin(), vec.end());
       return vec;
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