class Solution {
public:
   int solve(vector<int>& nums, int target, int pos)
    {
        int n = nums.size(), i;
       int ans = -1;
        int l=0, r = n-1;
          while(l<=r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                cout<<mid<<" ";
                if(pos==1)
                    r = mid-1;
                else 
                    l = mid+1;                
            }
            else if(nums[mid] < target)
            {
                l= mid+1;
            }
            else
                r = mid-1;
        }
       return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       
        vector<int>vec(2, -1);
      
       int first = solve(nums, target, 1);
        if(first==-1)
            return vec;
        cout<<endl;
        int second = solve(nums, target, 2);
        if(second==-1)
            return vec;
        vec[0]= first;
        vec[1]= second;
        return vec;
        
    }
};