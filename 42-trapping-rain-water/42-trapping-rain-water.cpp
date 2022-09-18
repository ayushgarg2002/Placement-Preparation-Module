// class Solution {
// public:
//     int trap(vector<int>& ht) {
//         int i, j, k, n=ht.size(),  res=0;
//         vector<int>left(n, 0);
//         vector<int>right(n, 0);
//         left[0]=ht[0];
//         for(i=1; i<n ; i++)
//         {
//             left[i] = max(ht[i], left[i-1]);
//         }
//         right[n-1] = ht[n-1];
//         for(j=n-2; j>=0; j--)
//         {
//             right[j] = max(ht[j], right[j+1]);
//         }
//         for(i=0; i<n; i++)
//         {
//             cout<<left[i]<<" ";
//         }
//         cout<<endl;
//         for(i=0; i<n; i++)
//         {
//             cout<<right[i]<<" ";
//         }
//         for(i=0; i<n; i++)
//         {
//             res+= min(right[i], left[i]) - ht[i];
//         }
//         return res;
        
//     }
// };

class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int low = 0, hi = n-1, left_max = 0, right_max = 0, res=0;
        
        while(low <= hi)
        {
            if(ht[low] <= ht[hi])
            {
                // current ht bdi h yaha pani nhi rukaga
                if(ht[low] > left_max)
                {
                    left_max = ht[low];
                }
                else
                    res+= left_max - ht[low];
                low++;
            }
            else{
                if(ht[hi] > right_max)
                {
                    right_max = ht[hi];
                }
                else
                    res+= right_max - ht[hi];
                hi--;
            }
        }
        return res;
    }
};