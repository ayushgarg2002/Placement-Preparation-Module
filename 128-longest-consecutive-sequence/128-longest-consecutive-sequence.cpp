class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int i, n= nums.size(),cnt=1, maxi=0;
        for(i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        
        for(i=0;i<n;i++)
        {
            cnt=1;
            int k= nums[i];
            if(s.find(nums[i]-1)!=s.end())
                continue;
            
            else {
                int k = nums[i]+1;
                while(s.find(k)!=s.end())
                {
                    cnt++;
                    k++;
                } 
               
            }
            maxi= max(maxi, cnt);
        }
        return maxi;
    
    }
};