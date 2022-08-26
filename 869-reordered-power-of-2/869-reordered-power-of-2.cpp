class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int i;
        stringstream ss;
        ss<<n;
        string s, str;
        ss>>s;
        cout<<s;
        sort(s.begin(), s.end());
        vector<string> vec;
        ss.clear();
        
        for(i=0; i<31; i++)
        {
            int k = pow(2, i);
            ss<<k;
            ss>>str;
            sort(str.begin(), str.end());
            vec.push_back(str);
            str = "";
            ss.clear();
        }
        
        for(i=0; i<31; i++)
        {
            if(vec[i]==s)
                return true;
        }
        return false;
        
    }
    
};