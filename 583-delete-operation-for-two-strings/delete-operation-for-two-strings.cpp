class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        int result=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        if(abs(n-m)>0){
            result=max(n,m)-ans;
            if(ans!=min(n,m)){
                result+=min(n,m)-ans;
            }
        }else{
            result=(n-ans)*2;
        }
        return result;
        
        /*
        int result=(n+m)-2*ans;
        return result;
        */
        
    }
};