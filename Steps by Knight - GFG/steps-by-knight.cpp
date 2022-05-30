// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   
	    int a= KnightPos[0];
	    int b= KnightPos[1];
	    int c= TargetPos[0];
	    int d= TargetPos[1];
	    if(a==c && b==d)
	    return 0;
	    
        int arr[1000][1000];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            arr[i][j]=0;
        }
	   queue<pair<int,int>> q;
	   q.push(make_pair(a-1, b-1));
	   
	    while(!q.empty())
	    {
	        auto curr = q.front();
	        
	        int x= curr.first;
	        int y= curr.second;
	        q.pop();
	        if((x+1)>=0 && (x+1)<N && (y+2)>=0 && (y+2)<N && arr[x+1][y+2]==0){
	            arr[x+1][y+2]= arr[x][y]+ 1;
	            q.push(make_pair(x+1, y+2));
	        }
	        if((x-1)>=0 && (x-1)<N && (y+2)>=0 && (y+2)<N && arr[x-1][y+2]==0){
	            arr[x-1][y+2]= arr[x][y]+ 1;
	            q.push(make_pair(x-1, y+2));
	        }
	        if((x-2)>=0 && (x-2)<N && (y+1)>=0 && (y+1)<N && arr[x-2][y+1]==0){
	            arr[x-2][y+1]= arr[x][y]+ 1;
	            q.push(make_pair(x-2, y+1));
	        }
	        if((x+2)>=0 && (x+2)<N && (y+1)>=0 && (y+1)<N && arr[x+2][y+1]==0){
	            arr[x+2][y+1]= arr[x][y]+ 1;
	            q.push(make_pair(x+2, y+1));
	        }
	        if((x-1)>=0 && (x-1)<N && (y-2)>=0 && (y-2)<N && arr[x-1][y-2]==0){
	            arr[x-1][y-2]= arr[x][y]+ 1;
	            q.push(make_pair(x-1, y-2));
	        }
	        if((x+1)>=0 && (x+1)<N && (y-2)>=0 && (y-2)<N && arr[x+1][y-2]==0){
	            arr[x+1][y-2]= arr[x][y]+ 1;
	            q.push(make_pair(x+1, y-2));
	        }
	        if((x-2)>=0 && (x-2)<N && (y-1)>=0 && (y-1)<N && arr[x-2][y-1]==0){
	            arr[x-2][y-1]= arr[x][y]+ 1;
	            q.push(make_pair(x-2, y-1));
	        }
	        if((x+2)>=0 && (x+2)<N && (y-1)>=0 && (y-1)<N && arr[x+2][y-1]==0){
	            arr[x+2][y-1]= arr[x][y]+ 1;
	            q.push(make_pair(x+2, y-1));
	        }
	        
	    }
	    return arr[c-1][d-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends