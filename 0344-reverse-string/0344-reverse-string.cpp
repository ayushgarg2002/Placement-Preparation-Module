class Solution {
public:
    void reverseString(vector<char>& s) {
        char c;
        int i, n=s.size(), j;
        for(i=0, j=n-1; i<j; i++, j--)
        {
            swap(s[i], s[j]);
        }
        
    }
};