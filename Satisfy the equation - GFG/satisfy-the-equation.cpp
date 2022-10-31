//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        map<pair<int,int>, int> mp;
        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                mp[{i,j}]=A[i]+A[j];
            }
        }
        
        for(auto i:mp) {
            for(auto j: mp) {
                if(i.second==j.second && 
                i.first.first!=j.first.first && 
                i.first.second!=j.first.second && 
                i.first.second!=j.first.first) {
                    return {i.first.first, i.first.second, j.first.first, j.first.second};
                }
            }
        }
        return {-1, -1, -1, -1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends