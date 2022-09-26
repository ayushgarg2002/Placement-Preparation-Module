class Solution {
public:
    bool solve(vector<vector<int>>& graph,int first,int second,vector<int>& vis){
        if(first==second){
            return false;
        }
        vis[first]=1;
        for(int i=0;i<graph[first].size();i++){
            int k=graph[first][i];
            if(!vis[k] && !solve(graph,k,second,vis)){
                return false;
            }
        }
        return true;
    }
	
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        vector<vector<int>> graph(26);
        
        for(int i=0;i<n;i++){
            string eq=equations[i];
            int first=eq[0]-'a';
            int second=eq[3]-'a';
            if(eq[1]=='='){
                if(first!=second){
                    graph[first].push_back(second);
                    graph[second].push_back(first);
                }
            }
        }
        for(int i=0;i<n;i++){
            string eq=equations[i];
            int first=eq[0]-'a';
            int second=eq[3]-'a';
            if(eq[1]=='!'){
                vector<int> vis(26,0);
                if(!solve(graph,first,second,vis)){
                    return false;
                }
            }
        }
        return true;
    }
};
