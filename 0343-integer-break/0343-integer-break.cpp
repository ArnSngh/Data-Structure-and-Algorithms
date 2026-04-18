class Solution {
public:
    int integerBreak(int n) {
        if(n<4)
        return n - 1;
        int n3=n/3;
        long long p=pow(3,n3);
        if(n%3==1) 
        {
            p/=3;
            p*=4;
        } 
        else if(n%3==2) 
        p*=2;
        return p;
    }
};