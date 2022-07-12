class Solution {
public:
  bool solve(int ind, vector<int>&matchsticks, vector<int>&vec, int target)
  {
      if(ind==matchsticks.size())
      {
          if(vec[0]==vec[1] && vec[1]==vec[2] && vec[2]==vec[3]){
              return true;
          }
        return false;
                                    
      }
      
      for(int i=0;i<4;i++)
      {
          if(vec[i] + matchsticks[ind] > target)
              continue;
          int j= i-1;
          while(j>=0)
          {
              if(vec[i]==vec[j])
                  break;
              j--;
          }
          if(j!=-1)
              continue;
          vec[i] += matchsticks[ind];
          if(solve(ind+1, matchsticks, vec, target))
              return true;
          vec[i]-=matchsticks[ind];
      }
      return false;
  }
    bool makesquare(vector<int>& matchsticks) {
     vector<int> vec(4, 0) ;
        int n= matchsticks.size(), i,j, sum=0;
        for(i=0;i<n;i++)
            sum+= matchsticks[i];
        if(sum==0 || sum%4!=0)
            return false;
        int target = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(solve(0, matchsticks, vec, target))
            return true;
        return false;
        
    }
};