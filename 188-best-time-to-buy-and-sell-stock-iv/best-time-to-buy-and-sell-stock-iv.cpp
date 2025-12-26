class Solution {
public:
/*
int solve(int ind,int buy,int cap,int n,vector<int>& prices,vector<vector<vector<int>>>& dp){
    if(cap==0) return 0;
    if(ind==n) return 0;
    if(dp[ind][buy][cap]!=-1){
        return dp[ind][buy][cap];
    }
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+solve(ind+1,0,cap,n,prices,dp),0+solve(ind+1,1,cap,n,prices,dp));

    }else{
        profit=max(prices[ind]+solve(ind+1,1,cap-1,n,prices,dp),0+solve(ind+1,0,cap,n,prices,dp));
    }
    return dp[ind][buy][cap]=profit;

}
*/
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
                        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    }else{
                        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};