//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	   int n = nums.size();
	    vector<int> count(n);
	    for(int i=0; i<n; i++)
	    {
	        int val =0;
	        for(int j=i+1; j<n; j++)
	            if(nums[j]>nums[i])
	                val++;
	        count[i] = val;
	    }
	    int ans=0;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=i+1; j<n; j++)
	        {
	            if(nums[j]>nums[i])
	                ans+=count[j];
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends