//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	  int dist_from_target(int arr[], int n, int idx, int current_sum, int target)
    {
        
        // Assuming arr is already sorted
        // printf("Idx=%d, current_sum=%4d, target=%4d\n", idx, current_sum, target);
        // if((idx < n) && (memo[idx] != -1))
        // {
        //     return memo[idx]
        // }
        if((current_sum >= target) || (idx >= n))
        {
            return current_sum - target;
        }
        else
        {
            int num = arr[idx];
            int with_num = dist_from_target(arr, n, idx+1, current_sum+num, target);
            if(with_num == 0)
            {
                return 0;
            }
            if(with_num < 0)
            {
                with_num = -with_num;
            }
            int without_num = dist_from_target(arr, n, idx+1, current_sum, target);
            if(without_num < 0)
            {
                without_num = -without_num;
            }
            // printf("with_num=%4d, without_num=%4d\n", with_num, without_num);
            int min_dist = (with_num < without_num) ? (with_num) : (without_num);
            
            return min_dist;
        }
        
    }
	int minDifference(int arr[], int n)  { 
	    
	    int sum = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        sum += arr[i];
	    }
	    
	    int target_sum = sum / 2;
	    
	    // Find a set with the nearest sum to target sum/
	    int set_sum = 0;
	    
	    sort(arr, arr + n);
	   // vector<int> memo(n, -1);
	    int sets_diff = 2 * dist_from_target(arr, n, 0, set_sum, target_sum);
	    if(sum%2 == 1)
	    {
	        sets_diff++;
	    }
	    return sets_diff; 
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends