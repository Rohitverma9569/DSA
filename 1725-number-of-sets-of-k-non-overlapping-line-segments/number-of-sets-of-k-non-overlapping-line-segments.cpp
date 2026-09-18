class Solution {
public:
int M=1000000007;
/*

    long long solve(int n,int k,int i,vector<vector<long long>>& dp){
        if(k==0){
          return 1;
        }
        if(i>=n) return 0;
        if(dp[k][i]!=-1){
            return dp[k][i];
        }
        long long skip=(solve(n,k,i+1,dp))%M;
        long long take=0;
        for(int j=i+1;j<n;j++){
           take=(take+(solve(n,k-1,j,dp))%M)%M;
        }
        return dp[k][i]=(take+skip)%M;
    }
    */
    int numberOfSets(int n, int k) {
        vector<vector<long long>>dp(1001,vector<long long>(1001,0));
        //return solve(n,k,0,dp);
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int K=1;K<=k;K++){
            vector<int>prevRow(n+1,0);
            for(int x=n-1;x>=0;x--){
                prevRow[x]=(prevRow[x+1]+dp[K-1][x])%M;
            }
            for(int i=n-1;i>=0;i--){
                long long skip=dp[K][i+1];                            
                long long take=prevRow[i+1];
                dp[K][i]=(take+skip)%M;              
             }
        }
        return dp[k][0];

    }
};