class Solution {
public:
    int maxArea(vector<int>& ht) {
        int i, n= ht.size();
        int low = 0, hi=n-1;
        int res=0;
        while(low < hi)
        {
            int val = min(ht[low], ht[hi]);
            int amt = (hi - low);
            res  =  max(res, amt*val);
            
            ht[low]<ht[hi]? low++ : hi--;
            
        }
        return res;
    }
};