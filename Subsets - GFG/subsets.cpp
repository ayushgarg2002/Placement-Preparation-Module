// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution
{
    void solve(int idx, vector<int> v, vector<int> ds, vector<vector<int>>&res){
        if(idx == v.size()){
            res.push_back(ds);
            return;
        }
    
        ds.push_back(v[idx]);
        solve(idx+1, v, ds, res);
        ds.pop_back();
        
        solve(idx+1, v, ds, res);
    }
    
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> res;
        vector<int> ds;
        
        solve(0, A, ds, res);
        sort(res.begin(), res.end());
        return res;
    }
};


// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends