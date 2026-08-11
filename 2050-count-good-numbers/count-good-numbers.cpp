class Solution {
public:
long long mod=1000000007;
long long power(long long x, long long y){
    if(y==0){
        return 1;
    }
    long long half=power(x,y/2)%mod;
    long long ans=(half*half)%mod;
    if(y%2){
        ans*=x;
    }
    return ans%mod;
}
    int countGoodNumbers(long long n) {
        long long  even=(n+1)/2;
        long long odd=n/2;
        return (power(5,even)*power(4,odd))%mod;        
    }
};