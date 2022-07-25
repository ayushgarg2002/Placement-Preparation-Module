class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n+1);
        
        //making graph from the path vector
        for(auto &p: paths){
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        //a vector of avaible colors; color 1 to 4 should be taken; 1 means ith color is available, 0 means not
        vector<int> available(5, 1); 
        //color of each node; initially all uncolored
        vector<int> nodeColor(n, -1);
        
        for(int i= 1; i<= n; i++){
            
            //marking all the colors used by adjacent colored nodes as unavailable for use
            for(auto &adj: graph[i]){
                if(nodeColor[adj-1]!= -1)
                    available[nodeColor[adj-1]]= 0;
            }
            
            //finding any color that is available for use
            int col= -1;
            for(int i=1; i<available.size(); i++){
                if(available[i]== 1){
                    col= i;
                    break;
                }
            }
            
            //coloring the node with the found available color
            nodeColor[i-1]= col;
            
            //resetting the colors of the adj nodes to available
            for(auto &adj: graph[i]){
                if(nodeColor[adj-1]!= -1)
                    available[nodeColor[adj-1]]= 1;
            }
            
        }
        
        return nodeColor;
    }
};