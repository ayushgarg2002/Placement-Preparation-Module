// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	     int v1=0, v2=0;
	    int n = Query.size();
	    vector<int> res;
	    for(int j=0;j<n;j++)
	    {
	    int cnt=0;
	    int l = Query[v1][0];
	    int r = Query[v1][1];
	    v1++;
	    vector<int>vec(26,0);
	    ;
	    for(int i=l; i<=r; i++)
	    {
	        vec[str[i-1]-'a']++;
	    }
	    for(int i=0;i<26;i++)
	    {
	        if(vec[i]>=1)
	        cnt++;
	    }
	    res.push_back(cnt);
	    
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends