class Solution {
public:
int solve(vector<int>& coins,int ind,int tar,vector<vector<int>>& dp){
    
    if(ind==0){
        if(tar==0){
            return 1;
        }
        else if(tar%coins[0]==0){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[ind][tar]!=-1){
        return dp[ind][tar];
    }
    int notTake=solve(coins,ind-1,tar,dp);
    int take=0;
    if(coins[ind]<=tar) take=solve(coins,ind,tar-coins[ind],dp);
    return dp[ind][tar]=take+notTake;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,n-1,amount,dp);
    }
};