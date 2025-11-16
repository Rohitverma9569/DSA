class Solution {
public:
const long long mod=1000000007;
    int numSub(string s) {
        int n=s.size();
        long long i=0;
        long long j=0;
        long long  ans=0;
        while(j<n){
            if(s[j]=='1'){
               j++; 
            }
            else{
                long long k=((j-i)*(j-i+1))/2;
                if(s[i]=='1' && k==1){
                    ans+=k;
                }
                if(k>1){
                    ans+=k;
                    
                }
                
                j++;
                i=j;
            }
            if(j==n-1 && s[j]=='1'){
                long long k=((j-i+1)*(j-i+2))/2;
                if(s[j]=='1' && k==1){
                    ans+=k;
                    
                
                }
                if(k>1){
                    ans+=k;
                    
                }
                ans=ans%mod;

            }
        }
        return ans;
        
        
    }
};