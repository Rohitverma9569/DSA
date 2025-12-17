class Solution {
public:
/*
int solve(vector<int>& nums){
    int n=nums.size();
    int prev1=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=prev2;
        int notPick=prev1;
        int curr=max(pick,notPick);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
*/
int solve(int ind,vector<int>&nums,vector<int>& dp){
    if(ind==0){
        return nums[0];
    }
    if(ind<0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int take=nums[ind]+solve(ind-2,nums,dp);
    int notTake=0+solve(ind-1,nums,dp);
    return dp[ind]=max(take,notTake);
}

    

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        int l= solve(n-2,nums,dp1);
        nums.erase(nums.begin());
        vector<int>dp2(n,-1);
        int r=solve(n-2,nums,dp2);
        return max(l,r);
        
        

        
    }
};