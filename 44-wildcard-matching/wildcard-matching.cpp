class Solution {
public:
/*
bool solve(int i,int j, string p, string s){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(i>=0 && j<0){
        for(int ii=0;ii<i;ii++){
            if(p[ii]!='*') return false;
        }
        return true;
    }
    
    if(p[i]==s[j] || p[i]=='?'){
        return solve(i-1,j-1,p,s);

    }
    if(p[i]=='*'){
        return solve(i-1,j,p,s) || solve(i,j-1,p,s);

    }
    return false;
}
*/
    bool isMatch(string s, string p) {
        /*
        int n=p.size();
        int m=s.size();
        return solve(n-1,m-1,p,s);
        */
        int n=p.size();
        int m=s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            dp[0][j]=false;
        }
        //j==0
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(p[i-1]==s[j-1] || p[i-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                dp[i][j]=dp[i-1][j] || dp[i][j-1];

                }
                else {
                    dp[i][j]=false;
                }

            }
        }
        return dp[n][m];



        
        
    }
};