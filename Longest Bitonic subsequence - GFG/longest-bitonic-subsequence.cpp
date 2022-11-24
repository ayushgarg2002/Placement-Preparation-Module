//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>n)
	{
	     int size=n.size();
       
       
        vector<int> v1(size,1);
        for(int ind=0;ind<size;ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if(n[prev]<n[ind])
                {
                    v1[ind]=max(v1[ind],1+v1[prev]);
                }
                
            }
        }
       
       vector<int> v2(size,1);
        for(int ind=size-1;ind>=0;ind--)
        {
            for(int prev=size-1;prev>ind;prev--)
            {
                if(n[prev]<n[ind])
                {
                    v2[ind]=max(v2[ind],1+v2[prev]);
                }
            }
        }
       
         int maxi=INT_MIN;
         for(int i=0;i<size;i++)
         { 
                 maxi=max(maxi,v1[i]+v2[i]-1);
             
         }
         return maxi;
         
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends