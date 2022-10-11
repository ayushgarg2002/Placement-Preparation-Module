//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int last_digit=0;
    string ans="";
    stack<pair<int, string>>stck;
    void decode(string& str, string temp, int i){
        if(i==str.size()){
            ans=temp;
            return;
        }
        if(isdigit(str[i])){
            while(isdigit(str[i])){
                last_digit*=10;
                last_digit+=str[i]-'0';
                i++;
            }
            decode(str, temp, i);
        }
        else if(str[i]=='['){
            stck.push(make_pair(last_digit, temp));
            temp="";
            last_digit=0;
            decode(str, temp, i+1);
        }
        else if(str[i]==']'){
            pair<int, string>p=stck.top();
            stck.pop();
            p.first--;
            // cout<<p.first<<" "<<temp<<'\n';
            string temp2=temp;
            while(p.first--)temp+=temp2;
            temp.insert(0, p.second);
            decode(str, temp, i+1);
        }
        else{
            temp+=str[i];
            decode(str, temp, i+1);
        }
    }
    string decodedString(string s){
        // code here
        int i=0;
        string temp="";
        decode(s, temp, i);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends