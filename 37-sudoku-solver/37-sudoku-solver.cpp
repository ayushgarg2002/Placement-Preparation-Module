class Solution {
public:
    bool isPossible(int i, int j, int k, vector<vector<char>>& board)
    {
        for(int t=0;t<9;t++)
        {
            if(board[i][t]==k)
                return false;
        }
        for(int t=0;t<9;t++)
        {
            if(board[t][j]==k)
            return false;
        }
        
        for(int t=0;t<9;t++)
        {
            if(board[3*(i/3) + t/3][3*(j/3)+ t%3]==k)
                return false;
        }
        return true;
    }
    bool solveNow(vector<vector<char>>& board){
                int i,j;
        
        for(i=0;i<9;i++){
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isPossible(i,j,k,board))
                        {
                            board[i][j]= k;
                            bool correct = solveNow(board);
                            if(correct)
                                return true;
                            else
                                board[i][j]='.';
                        }
                        
                    } 
                    return false;
                }
               
            }
            
    }
        return true;
}
    
    
   void solveSudoku(vector<vector<char>>& board) {
        solveNow(board);
   }
};