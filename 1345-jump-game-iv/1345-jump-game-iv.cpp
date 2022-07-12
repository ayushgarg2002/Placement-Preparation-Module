class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1) return 0;
        if(arr[0] == arr[n-1]) return 1;
        
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        int count = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int ind = q.front();
                q.pop();
                
                if(ind == n-1) return count;
                
                int backInd = ind-1;
                int forwardInd = ind+1;
                
                if(backInd>=0 && mp.find(arr[backInd]) != mp.end())  {
                    q.push(backInd);
                }
                
                if(forwardInd<n && mp.find(arr[forwardInd]) != mp.end()){
                    q.push(forwardInd);
                }
                
                if(mp.find(arr[ind]) != mp.end()){
                    for(auto equalInd : mp[arr[ind]]){
                        if(equalInd != ind){
                            q.push(equalInd);
                        }
                    }
                }
                mp.erase(arr[ind]);
            }
            count++;
        }
        
        return -1;
    }
};