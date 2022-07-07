// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    // bool SolveSudoku(int grid[N][N])  
    // { 
    //     // Your code here
    // }
     bool isPossible(int i, int j, int k, int board[N][N])
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
    bool SolveSudoku(int board[N][N]) { 
                int i,j;
        
        for(i=0;i<9;i++){
            for(j=0;j<9;j++)
            {
                if(board[i][j]==0)
                {
                    for(char k=1;k<=9;k++)
                    {
                        if(isPossible(i,j,k,board))
                        {
                            board[i][j]= k;
                            bool correct = SolveSudoku( board);
                            if(correct)
                                return true;
                            else
                                board[i][j]=0;
                        }
                        
                    } 
                    return false;
                }
               
            }
            
    }
        return true;
}
  
    
    //Function to print grids of the Sudoku.
   void printGrid(int grid[N][N])
        {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << ' ';
    }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends