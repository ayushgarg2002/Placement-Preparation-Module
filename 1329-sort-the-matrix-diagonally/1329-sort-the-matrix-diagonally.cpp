class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int i, j,l,k,n=mat.size(),m= mat[i].size();
        vector<vector<int>> vec(n, vector<int>(m, 0));
        vector<int>v;
       
           for(j=0; j< n; j++)
            {
                   v.clear();
                for(l=j, k=0; k<m && l<n; l++,k++)
                {
                   v.push_back(mat[l][k]);
                }
               sort(v.begin(), v.end());
                for(l=j, k=0; k<m && l<n; l++,k++)
                {
                   vec[l][k]= v[k];
                }
                
            }
             for(j=1; j< m; j++)
            {
             v.clear();    
                for(l=j,k=0; k<n && l<m; l++,k++)
                {
                   v.push_back(mat[k][l]);
                }
                sort(v.begin(), v.end());
                for(l=j,k=0; k<n && l<m; l++,k++)
                {
                   vec[k][l]= v[k];
                }
            }
       

        return vec;
    }
};

