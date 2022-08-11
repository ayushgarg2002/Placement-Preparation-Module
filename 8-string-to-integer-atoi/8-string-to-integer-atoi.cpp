class Solution {
public:
    int myAtoi(string s) {
     stringstream ss;
    ss<<s;
        int x = 0;
     ss>>x;
        return x;
    }
};