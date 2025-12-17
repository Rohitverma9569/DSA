class Solution {
public:
    int solve(int i,int n,vector<int>& dp){
        
        if(i==n){
            return 1;
        
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int oneStep=solve(i+1,n,dp);
        int twoStep=solve(i+2,n,dp);
        dp[i]=oneStep+twoStep;
        return dp[i];
    }
    int climbStairs(int n) {
        int i=0;
        vector<int>dp(n+1,-1);
        return solve(i,n,dp);  
    }
};