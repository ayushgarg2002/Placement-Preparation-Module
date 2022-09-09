// GIVES TLE
// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& vec) {
//      int i, j, n=vec.size(), cnt=0;
//         sort(vec.begin(), vec.end());
//         for(i=0; i<n-1; i++)
//         {
//             for(j=i+1; j<n; j++)
//             {
//                 if(vec[i][0]<vec[j][0] && vec[i][1]<vec[j][1]){
//                     cnt++;
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& vec) {
     int i, j, n=vec.size(), cnt=0;
        sort(vec.begin(), vec.end(), cmp);
        int val  = INT_MIN;
        for(i=n-1; i>=0; i--)
        {
            if(vec[i][1] < val)
            {
                cnt++;
               
            }
                val = max(val, vec[i][1]);
        }
        return cnt;
        
    }
};

