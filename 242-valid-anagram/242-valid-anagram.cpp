class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec1(26, 0);
        vector<int>vec2(26, 0);
        if(s.length()!= t.length())
            return false;
        for(int i=0; i<t.length(); i++)
        {
            vec1[s[i]-'a']++;
            vec2[t[i]-'a']++;
            
        }
       
        for(int i=0; i<vec1.size(); i++)
        {
            if(vec1[i]!= vec2[i])
                return false;
        }
        return true;
        
    }
};