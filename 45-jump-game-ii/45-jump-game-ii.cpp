class Solution {
public:
    int jump(vector<int>& nums) {
        int i, j, maxR=nums[0], n=nums.size();
        int jump=1;
        int steps=nums[0];
       
        if(n==1){
            return 0;
        }
         if(nums[0]==0)
        return -1;
        for(i=1; i<n-1; i++)
        {
            maxR= max(maxR, i+nums[i]);
            steps--;
            if(steps==0)
            {
                jump++; 
                if(i>=maxR)
                return -1;
                steps = maxR-i;
            }
        }
        
    return jump;
    }
};
