//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
string addBinary(string A, string B){
	    // your code here
	    string res;
	    int carry = 0;
	    int i=0;
	    
	    reverse(A.begin(),A.end());
	    reverse(B.begin(),B.end());
	    while(i<A.length() || i<B.length() || carry != 0){
	        int count = 0;
	        if(i<A.length())count += (A[i] - '0');
	        if(i<B.length())count += (B[i] - '0');
	        count += carry;
	        carry = count/2;
	        char ch = (count%2 + '0');
	        res += ch;
	        i++;
	    }
	    
	    reverse(res.begin(),res.end());
	    i= 0;
	    while(res[i] == '0' && i < res.length())i++;
	    
	    return res.substr(i,res.length()-i);
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends