class Solution {
public:
/*
bool solve(int i,int j,string s,string p,vector<vector<int>>& dp){
    if(i==0 && j==0) return true;
    if(i==0 && j>0){
        for(int k=0;k<j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(i>0 && j==0) return false;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i-1]==p[j-1] || p[j-1]=='?'){
        return dp[i][j]=solve(i-1,j-1,s,p,dp);
    }
    if(p[j-1]=='*'){
        return dp[i][j]=solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
    }
    return dp[i][j]=false;
}
*/

    bool isMatch(string s, string p) { 
        /*
        int n=s.size();
        int m=p.size();
        vector<bool>curr(n+1,false),prev(n+1,false);
        prev[0]=1;
        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int k=0;k<=j;k++){
               if(p[k]!='*'){
                 flag=false;
                 break;
               }
            }
            prev[j]=flag;  
        }       
        for(int i=1;i<=n;i++){
            curr[0]=false;
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                       curr[j]=prev[j-1];
                }else if(p[j-1]=='*'){
                        curr[j]=prev[j] || curr[j-1];
                }
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[n];  
        */
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int k=0;k<j;k++){
                if(p[k]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }
        dp[0][0]=1; 
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j]=false;
                }
                
            }
        }
        return dp[n][m];
    }
};