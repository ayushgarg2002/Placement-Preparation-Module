// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

 class Solution{
 public:
//     int isValid(vector<vector<int>> mat){
//         // code here
//     }


int isValid(vector<vector<int>> mat){
       // code here
       map<string,int>mp;
       
       for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
           {
               int box = (i/3)*3+(j/3);
               if(mat[i][j]!=0)
               {
                   string s1 ="row" + to_string(i) +                 to_string(mat[i][j]);
                   string s2 ="col" + to_string(j) + to_string(mat[i][j]);
                   string s3 ="box" + to_string(box) + to_string(mat[i][j]);
                   mp[s1]++;
                   mp[s2]++;
                   mp[s3]++;
                   if(mp[s1]>1 || mp[s2]>1 || mp[s3]>1)
                   {
                       return 0;
                   }
               }
               
           }
     
       }
       
       return 1;
   }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends