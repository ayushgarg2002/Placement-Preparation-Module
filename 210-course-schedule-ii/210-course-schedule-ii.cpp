class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
        vector<int>res;
        int i, j;
        for(i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> ans;
	    vector<int> in(numCourses, 0);
	    queue<int> q;
	    for(i=0; i<numCourses; i++)
	    {
	        for(auto x: adj[i])
            {
    	       in[x]++;
	       
	        }
	    }
	    
	    for( i=0; i<numCourses; i++)
	    {
	        if(in[i]==0)
	        q.push(i);
	    }
	    

	    while(!q.empty())
	    {
	        auto td = q.front();
	        q.pop();
	        ans.push_back(td);
	        for(auto x: adj[td])
	        {
	            in[x]--;
	            if(in[x]==0)
	            q.push(x);
	        }
	    }
        if(ans.size()==numCourses) return ans;
        return res ;
        
    }
};
