class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
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
        return {};
        
    }
};
// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> ans;
//         vector<int> adj[numCourses];
//         for(int i=0;i<prerequisites.size();i++){
//             int u = prerequisites[i][0];
//             int v = prerequisites[i][1];
            
//             adj[v].push_back(u);
//         }
        
//         vector<int> indegree(numCourses, 0);
//         for(int i=0;i<numCourses;i++){
//             for(auto nbr: adj[i]){
//                 indegree[nbr]++;
//             }
//         }
        
//         queue<int> q;
//         for(int i=0;i<numCourses;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
        
//         while(!q.empty()){
//             int top = q.front(); q.pop();
//             ans.push_back(top);
//             for(auto nbr: adj[top]){
//                 indegree[nbr]--;
//                 if(indegree[nbr]==0){
//                     q.push(nbr);
//                 }
//             }
//         }
        
//         if(ans.size()==numCourses) return ans;
//         return {};
//     }
// };