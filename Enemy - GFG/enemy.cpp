//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
          int largestArea(int n,int m,int k,vector<vector<int>> &en)

        {

            vector<int>a,b;

            for (int i = 0; i < en.size(); i++)

            {

               a.push_back(en[i][0]);

               b.push_back(en[i][1]);

            }

            sort(a.begin(),a.end());

            sort(b.begin(),b.end());

            int maxi1=0,maxi2=0;

            if(k==0) return n*m;

 

            for (int i = 1; i < a.size(); i++)

            {

                maxi1=max(maxi1,a[i]-a[i-1]-1);

                maxi2=max(maxi2,b[i]-b[i-1]-1);

            }

            int t=0;

             maxi1=max(maxi1,a[0]-t-1);

                maxi2=max(maxi2,b[0]-t-1);

             maxi1=max(maxi1,n-a[k-1]);

                maxi2=max(maxi2,m-b[k-1]);

                return maxi1*maxi2;

 

 

 

 

            

        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends