class Solution {
public:
    bool canConstruct(string s1, string s2) {
     map<char, int> map1;
     map<char, int> map2;
     int i,j,n=s1.length(),m = s2.length();
        int maxi = max(n,m);
        for(i=0; i<n; i++ )
        {
            map1[s1[i]]++;
        }
        for(i=0; i<m; i++ )
        {
            map2[s2[i]]++;
        }
        for(auto x: map1)
        {
          if(map2[x.first] < x.second)    
              return false   ;
        }
        
          
        return true;
    }
};