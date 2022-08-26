class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> vec;
        int sum=0,i, n= nums.size(),j,k,p;
        set<vector<int>>s;
        sort(nums.begin(), nums.end());
        for(i=0; i<n; i++)
        {
            // int val  = 0 - nums[i];
            // int total=0-nums[i];
            j=i+1; p=n-1;

            // for( j=i+1,p=n-1; j<p; j=j,p=p)
            while(j<p)
            {
                if(nums[i]+nums[j]+nums[p]==0)
                {
                    vector<int> v={nums[i],nums[j],nums[p]};
                    s.insert(v);
                    j++;p--;
                }
              else if(nums[i]+nums[j]+nums[p]<0)
                {
                    j++;
                }
                else
                {
                    p--;
                }

            }
        }
        for(auto x: s)
        {
            vec.push_back(x);
        }
        return vec;
    }
};
