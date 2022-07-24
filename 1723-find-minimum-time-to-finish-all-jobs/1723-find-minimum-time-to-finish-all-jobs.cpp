class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int res = INT_MAX;
        int len = pow(2, jobs.size()); 

		vector<vector<int>> dp(k, vector<int>(len, 1717171717171717));
        
        for(int i = 0; i < len; i++){       
            int sum = 0;
            for(int j = 0; j < jobs.size(); j++){
                if(i & (1 << j)) sum += jobs[j];
            }
		
            dp[0][i] = sum;
        }
        
        for(int t = 1; t < k; t++){
            for(int i = 0; i < len; i++){
                for(int j = i; j; j = (j-1)&i){
					
                    dp[t][i] = min(dp[t][i], max(dp[t-1][j], dp[0][j ^ i]));
                }
            }   
        }
        
        return dp[k-1][len-1];
    }
};