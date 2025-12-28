class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long k=max(need1,need2);
        long long buyBoth=1LL*costBoth*k;
        long long buyInd=1LL*cost1*need1+1LL*cost2*need2;
        long long mixBuy=0;
        if(need1>need2){
             mixBuy=1LL*costBoth*need2+1LL*cost1*(need1-need2);
        }
        else{
            mixBuy=1LL*costBoth*need1+1LL*cost2*(need2-need1);
            
        }
        
        long long ans=min({buyInd,buyBoth,mixBuy});
        return ans;

        
    }
};