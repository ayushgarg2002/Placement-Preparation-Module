//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        int cnta = 0;
        int cntb = 0;
        if(M != N) return 0;
        for(int i = 0;i<N;i++)
        {
            if(T[i] == 'A') cnta++;
            if(S[i] == 'A')
            {
                if(cnta == 0 || cntb != 0) return 0;
                cnta--;
            }
            if(S[i] == 'B') cntb++;
            if(T[i] == 'B')
            {
                if(cntb == 0 || cnta != 0) return 0;
                cntb--;
            }
        }
        if(cnta != 0) return 0;
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends