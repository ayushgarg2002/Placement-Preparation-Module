class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size(), i;
     vector<int>g[numCourses];
        for(i=0; i<n;i++)
        {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>in(numCourses, 0);
        queue<int> q;
        for(i=0; i<numCourses; i++)
        {
            for(auto x: g[i])
            in[x]++;
        }
        for(i=0; i<numCourses; i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            auto td = q.front();
            q.pop(); cnt++;
            for(auto x: g[td])
            {
                in[x]--;
                if(in[x]==0){
                   
                    q.push(x);
                }
                    
            }
        }
     if(cnt== numCourses)
         return true;
    return false;
        
    }
};