class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int low, high=0,cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            low = nums[i] - nums[i-1];
            if((low>0 && high<=0) || (low<0 && high>=0))
            {
                cnt++;
                high= low;
            }
        }
        return cnt;
    }
};