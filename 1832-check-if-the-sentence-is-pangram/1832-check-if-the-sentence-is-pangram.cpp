class Solution {
public:
    bool checkIfPangram(string sentence) {
        int i, j, n = sentence.size();
        if(n<26)
            return false;
        vector<int>vec(26, 0);
        for(i=0; i<n; i++)
        {
            vec[sentence[i]-'a']++;
        }
        for(i=0; i<26; i++)
        {
            if(vec[i]==0)
                return false;
        }
        return true;
    }
};