class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i,n=nums.size(), rep=-1, miss=-1;
        
        for(i=0; i<n; i++)
        {
            if(nums[abs(nums[i]) -1 ] > 0)
            {
                nums[abs(nums[i]) - 1]= -nums[abs(nums[i]) - 1];
            }
            else{
                rep=abs(nums[i]);
            }
        }
        for(i=0; i<n; i++)
        {
            if(nums[i]>0)
                miss=i + 1;
        }
        return {rep, miss};
    }
};