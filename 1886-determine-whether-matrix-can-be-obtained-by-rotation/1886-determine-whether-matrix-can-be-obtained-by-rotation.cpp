class Solution {
public:
    void solve(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        
        int i,j,n=mat.size();
        for(i=0; i<n; i++)
        {
            for(j=0; j<i; j++)
                swap(mat[i][j], mat[j][i]);
        }
        for(i=0; i<n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
       
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        solve(mat, target);
         if(mat==target)
            return true;
        for(int i=0; i<3; i++){
             solve(mat, target);
         if(mat==target)
            return true;
        
    }
        
        for(int i=0; i<mat.size();i++)
        {
            for(int j=0; j<mat.size(); j++){
              cout<<mat[i][j]<<" ";
            }                
             cout<<endl;
        }
         
    return false;
    }
    
};