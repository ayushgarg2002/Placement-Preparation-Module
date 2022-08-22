class Solution {
public:
    bool isPowerOfFour(int n) {
        long long m = n;
        // long long k = sqrt(n);
        // k = sqrt(k);
        // cout<<k;
        // long long v = k*k*k*k;
        // if(v==m)
        //     return true;
        // return false;
        if(n==0)
            return false;
        while(1)
        {
            if(n==1 || n==4)
                return true;
            if(n%4!=0)
                return false;
            n= n/4;
        }
            
            
    }
};

bool isPowerOfFour(int n) {
    
    if(n==0) return false;
    
    while (1){
        if(n==1 || n==4) return true;
        if(n%4!=0) return false;
        n=n/4;
    };
    return true;
}