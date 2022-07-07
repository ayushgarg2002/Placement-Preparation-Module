// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
unordered_map<string, int> dp;
//map ki values me initially 0 hota hai
bool checkString(string str,  vector<string> &B)
{
    int len = B.size();
    for(int i=0;i<len; i++)
    {
        if(str==B[i])
        return true;
    }
    return false;
}
int solve(string A, vector<string> &B)
{
     int i,j,n;
     n = A.length();
     
      if(n==0)
      return 1;
      
      if(dp[A]!=0)
      return dp[A];
      
       for(i=1;i<=n;i++)
       {
           int f=0;
           string str = A.substr(0, i);
        //   for(int j=0;j<B.size(); j++){
        //       if(str.compare(B[j])==0){
        //           f=1;
        //           break;
        //       }
               
        //   }
           if(checkString(str, B) && solve(A.substr(i, n-i), B)==1)
           return dp[A]=1;
        //   if(checkString(str, B))
        //   {
        //     if(solve(A.substr(i, n-i), B));
        //     return dp[A]=1;
        //   }
          
           
       }
       return dp[A]=-1;
}
    int wordBreak(string A, vector<string> &B) {
      int x= solve(A, B);
      if(x==1)
      return 1;
      else
      return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends