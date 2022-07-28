class Solution {
public:
bool canMeasureWater(int x, int y, int t) {
    
    if(x+y<t) return false;  //maxCapacity=x+y
    
    unordered_map<int,bool> vis;
    queue<int> q;
    q.push(0);
    vis[0]=true;
    
    int operation[4]={+x,+y,-x,-y};
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        
        if(curr==t) return true;
        
        for(int i=0;i<4;i++){
            int newCapacity = curr + operation[i];
            
            if(newCapacity==t) return true;
            
            if(newCapacity<0 || newCapacity>x+y) continue;
            
            if(vis.find(newCapacity)==vis.end()){
                q.push(newCapacity);
                vis[newCapacity]=true;
            }
        }
    }
    return false;
}
};