// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         multiset<int> s;
//         s.insert(nums[n-1]);
//         vector<int>vec(n);
//         vec[n-1]=0;
//         //cout<<0<<" ";
//         for(int i=n-2; i>=0;i--)
//         {
//             int k = nums[i];
//             s.insert(k);
//             int ind = 0;
//             for(auto u : s)
//             {
//                 if(u == k)
//                     break;
//                 ind++;
//             }
//            vec[i]= ind;
//             // cout<<ind<<" " ; 
            
//         }
//         return vec;
        
//     }
// };



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//Above three must de defined for ordered set to work
#define ordered_set tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return {0};
        vector<int> ans(n, 0);
        ordered_set o_s;
        for(int i=0; i<n; i++){
            o_s.insert({nums[i], i});
        }
        for(int i=0; i<n; i++){
            ans[i] = o_s.order_of_key({nums[i], -1});
            o_s.erase({nums[i], i});
        }
        return ans;
    }
};