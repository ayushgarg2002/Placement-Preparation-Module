class Solution {
public:
    void dfs(vector<int> vec[], vector<int>&vis, int x)
    { 
        vis[x]=1;
        for(auto k : vec[x])
        {
            if(!vis[k])   
            dfs(vec, vis, k);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
     int cnt=0,i,j;   
        int len = connections.size();
        if(n-1 > len)
            return -1;
        vector<int> vec[n];
        for(i=0;i<len;i++)
        {
            vec[connections[i][0]].push_back(connections[i][1]);
            vec[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>vis(n, 0);
        
        for(i=0;i<n; i++)
        {
            if(!vis[i]){
                    cnt++;
                    dfs(vec, vis, i);
                }
                    
            
        }
        return cnt-1;
        
    }
};
