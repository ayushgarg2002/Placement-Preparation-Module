class Solution {
public:
    vector<pair<int, int>> vec;
    static bool cmp(pair<int , int>&a, pair<int, int>&b)
    {
        return b. second < a.second;
    }
    void sortMapi(map<int, int> &mapi)
    {
       
        
        for(auto& it: mapi)
        {
            vec.push_back(it);
        }
        
        sort(vec.begin(), vec.end(), cmp);
    }
    int minSetSize(vector<int>& arr) {
      map<int, int> mapi;   
        int i, j;
        for(i=0; i<arr.size(); i++)
        {
            mapi[arr[i]]++;
        }
        
        sortMapi(mapi);
        int cnt=0, sum=0;
        for(i=0; i<vec.size(); i++)
        {
            if(sum>=arr.size()/2)
                return cnt;
            
            cnt++;
            sum+=vec[i].second;
            //cout<<vec[i].second<<" ";
        }
     return 1;   
    }
};