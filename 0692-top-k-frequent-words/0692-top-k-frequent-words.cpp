class Solution {
public:
    static bool cmp(pair<int, string>&a, pair<int, string>&b)
    {
        if(a.first!=b.first)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string>& word, int k) {
        map<string, int> mapi;
        vector<string> vec;
        int i,j, n=word.size();
        for(i=0; i<n; i++)
        {
            mapi[word[i]] ++;
        }
        map<string, int> :: iterator it;
        vector<pair<int, string>> pr;
        for(it=mapi.begin(); it!=mapi.end(); it++ )
        {
           pr.push_back({it->second, it->first});
        }
        sort(pr.begin(), pr.end(), cmp);
        
        for(auto &x : pr )
        {
            if(k){
                vec.push_back(x.second);
                k--;
            }
        }
        
        return vec;
        
        
    }
};