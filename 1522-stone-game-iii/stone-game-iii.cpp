class Solution {
public:
/*
vector<int>dp;
    int solve(vector<int>& stoneValue, int i){
        int n=stoneValue.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int result=stoneValue[i]-solve(stoneValue,i+1);
        if(i+1<n){

        
          result=max(result,stoneValue[i]+stoneValue[i+1]-solve(stoneValue,i+2));
        }
        if(i+2<n){
        result=max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(stoneValue,i+3));
        }
        return dp[i]=result;
    }
    */
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        //dp.resize(n+1,-1);
        //int diff=solve(stoneValue,0);
        vector<int>dp(n+1);
        
        for(int i=n-1;i>=0;i--){
            int result=stoneValue[i]-dp[i+1];
            if(i+1<n){
             result=max(result,stoneValue[i]+stoneValue[i+1]-dp[i+2]);
            }
            if(i+2<n){
              result=max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
            }
            dp[i]=result;
        }
        int diff=dp[0];
        if(diff>0){
            return "Alice";
        }
        if(diff<0){
            return "Bob";
        }
        return "Tie";


        
    }
};