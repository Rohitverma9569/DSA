class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        if(dividend>=0 && divisor<0) sign=false;
        if(dividend<0 && divisor>=0) sign=false;

        int ans=0;
        long  n=abs((long long)dividend);
        long d=abs((long long)divisor);
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans=ans+(1<<cnt);
            n=n-(d<<cnt);
        }
        if(ans==(1<<31) && sign) return INT_MAX;
        if(ans==(1<<31) && !sign) return INT_MIN;
        return sign?ans:-ans;
        
    }
};