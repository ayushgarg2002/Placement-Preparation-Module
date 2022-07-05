// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool isBool(string s, int p1,int p2)
    {
        while(p1<=p2)
        {
            if(s[p1++]!=s[p2--])
                return false;
        }
        return true;
    }
    void solve(int ind, vector<string>&ds, vector<vector<string>>&ans, string s)
    {
        if(ind==s.size())
        {
            ans.push_back(ds);
            return ;
        }
        
    for (int i = ind; i < s.size(); ++i) {
      if (isBool(s, ind, i)) {
        ds.push_back(s.substr(ind, i - ind + 1)); 
        solve(i + 1, ds, ans, s); 
        ds.pop_back();  
      }
    }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        solve(0, ds, ans, s);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends