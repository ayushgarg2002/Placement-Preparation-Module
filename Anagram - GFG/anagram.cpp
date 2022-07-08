// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    
bool isAnagram(string a, string b){
       
   int ch1[26] = {0};
   int ch2[26] = {0};
   for (int i = 0; i<a.length(); i++){
       int index = a[i] - 'a';
       ch1[index]++;
   }
   
   for (int i = 0; i<b.length(); i++){
       int index = b[i] - 'a';
       ch2[index]++;
   }
   
   for (int i = 0; i<26; ){
       if(ch1[i] == ch2[i]){
           i++;
       }
       else{
           return 0;
       }
   }
   return 1;
       
   }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends