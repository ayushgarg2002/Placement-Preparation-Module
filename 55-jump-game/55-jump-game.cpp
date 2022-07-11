class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR= nums[0], i;
        for(i=1; i<nums.size(); i++)
        {
            if(i>maxR)
                return false;
                
            maxR= max(maxR, i + nums[i]);
        }
        return true;
        
    }
};