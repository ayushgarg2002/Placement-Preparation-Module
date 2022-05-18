class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        int i,j;
        vector<int>vec;
        int n= nums.size();
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
             if(nums[i]+nums[j]==target)
                {
                vec.push_back(i);
                vec.push_back(j);
                return vec;
                }
            }
        }
        // for(i=0,j=n;i<j;i=i,j=j)
        // {
            // if(nums[i]+nums[j]==target)
            // {
            //     vec.push_back(i);
            //     vec.push_back(j);
            //     return vec;
            // }
        //     else if(nums[i]+nums[j]>target)
        //     {
        //         j--;
        //     }
        //     else
        //         i++;
        // }
        return vec;
    }
};