class Solution {
public:
    pair<int,int> find_cordinate(int value,int n){
        int r= n-1-(value-1)/n;  // value -1 for handling 6 in last row 12 in seocnd last row
        int c=(value-1)%n;
        if(r%2==n%2) {    // since there is a reversal in cell position after every row,
//              column is in zigzag manner so check for odd even respecrively 
            c=n-1-c;     // this check will take care of that
        }
        return {r,c};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<int>q;
        q.push(1);
        vis[n-1][0]=true;
        int steps=0;
        while(!q.empty()){
            int len=q.size();
            
            for(int i=0;i<len;i++){
                auto x=q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int k=1;k<=6;k++){
                    if(k+x>n*n) break;
                    auto p=find_cordinate(k+x,n);
                    int row=p.first;
                    int col=p.second;
//                      yha ab uske snkae ya ladder bhi check krenge aur true bhi
                    
                    if(vis[row][col]) continue;
                    
                    vis[row][col]=true;
                    if(board[row][col]==-1){
                        q.push(k+x);// ek agay  jaega
                    }
                    else{
                        q.push(board[row][col]);// snake ya ladder h
                    }
                }
            }
            steps++;
            
        }
        
        return -1;
      
        
    }
};