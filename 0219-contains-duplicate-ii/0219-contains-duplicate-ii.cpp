class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int i, j, n=nums.size();
        map<int, int>mapi;
        for(i=0; i<n; i++)
        {
            if(mapi.find(nums[i])!=mapi.end())
            {
                int val = mapi[nums[i]];
                if(abs(val-i)<=k)
                    return k;
                mapi[nums[i]] = i;
            }
            else{
                mapi[nums[i]] = i;
            }
        }
        return false;
    }
};