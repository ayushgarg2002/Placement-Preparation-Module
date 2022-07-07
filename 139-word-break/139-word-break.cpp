// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
        
//     }
// };
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
        
          if(checkString(str, B))
          {
            if(solve(A.substr(i, n-i), B)==1)
            return dp[A]=1;
          }
       }
       return dp[A]=-1;
}
     bool wordBreak(string A, vector<string>& B) {
      int x= solve(A, B);
      if(x==1)
      return true;
      else
      return false;
    }
};