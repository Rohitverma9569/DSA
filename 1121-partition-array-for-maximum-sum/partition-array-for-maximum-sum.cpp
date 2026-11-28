class Solution {
public:
int solve(int i,int n, int k,vector<int>& nums, vector<int>& dp){
    if(i==n) return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int maximumSum=INT_MIN;
    for(int j=i;j<n;j++){
        if(j-i+1<=k){
            int m=*max_element(nums.begin()+i, nums.begin()+j+1)*(j-i+1);
            int sum=m+solve(j+1,n,k,nums,dp);
            maximumSum=max(maximumSum,sum);
        }
    }
    return dp[i]=maximumSum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,k,arr,dp);
        
        
        
    }
};