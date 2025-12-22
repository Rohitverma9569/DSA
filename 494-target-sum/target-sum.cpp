class Solution {
public:
/*
int countPartitions(vector<int>& arr, int target,int sum,int ind,vector<vector<int>>& dp){
    if(ind==0){
        if((sum+arr[0]==target || sum-arr[0]==target ) && arr[0]==0){
            return 2;
        }
        if((sum+arr[0]==target || sum-arr[0]==target ) && arr[0]!=0){
            return 1;
        }
        return 0;
    }
    int plusTake=countPartitions(arr,target,sum+arr[ind],ind-1);
    int minusTake=countPartitions(arr,target,sum-arr[ind],ind-1);
    return plusTake+minusTake;
}
*/
int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totSum=0;
        for(int i=0;i<n;i++){
            totSum+=arr[i];
        }
        if((totSum-diff)<0 || (totSum-diff)%2==1){
            return 0;
        }
        int tar=(totSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(tar+1,0));
        if(arr[0]==0){
            dp[0][0]=2;
        }else{
            dp[0][0]=1;
        }
        if(arr[0]!=0 && arr[0]<=tar){
            dp[0][arr[0]]=1;
        }
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=tar;sum++){
                int notTake=dp[ind-1][sum];
                int take=0;
                if(arr[ind]<=sum) take=dp[ind-1][sum-arr[ind]];
                dp[ind][sum]=take+notTake;
            }
        }
        return dp[n-1][tar];
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        //return countPartitions(nums,target,0,n-1,dp);   
        return  countPartitions(nums,target);   
    }
};