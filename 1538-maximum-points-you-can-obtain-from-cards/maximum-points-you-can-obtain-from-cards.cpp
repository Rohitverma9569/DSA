class Solution {
public:
/*
int solve(int i,int j, vector<int>& cardPoints,int k, vector<vector<int>>& dp){
    if(k==0) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int leftCh=cardPoints[i]+solve(i+1,j,cardPoints,k-1,dp);
    int rightCh=cardPoints[j]+solve(i,j-1,cardPoints,k-1,dp);
    return dp[i][j]=max(leftCh,rightCh);
}
*/
    int maxScore(vector<int>& cardPoints, int k) {
        /*
        int n=cardPoints.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,cardPoints,k,dp);
        */
        int n=cardPoints.size();
        int leftSum=0;
        int rightSum=0;
        for(int i=0;i<k;i++) {
          leftSum+=cardPoints[i];
        }
        int sum=leftSum;
        int rightIdx=n-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[rightIdx];
            rightIdx--;
            sum=max(sum,leftSum+rightSum);
        }
        return sum;



        
    }
};