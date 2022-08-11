class Solution {
public:
    bool isPalindrome(int x) {
        long long rev =0;
         if(x<0)
             return false;
        long long val =x;
        while(val)
        {
            int k = val % 10;
            rev = (rev*10)+k; 
            val= val/10;
        }
        if(rev==x)
            return true;
        return false;
        
    }
};