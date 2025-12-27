class Solution {
public:
/*
int solve(int ind,int prev,int n,vector<int>& nums,vector<vector<int>>& dp){
    if(ind==n) return 0; 
    if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
    }
    int len=0+solve(ind+1,prev,n,nums,dp);
    
    if(prev==-1 || nums[ind]>nums[prev]){
        len=max(len,1+solve(ind+1,ind,n,nums,dp));
    }
    return dp[ind][prev+1]=len;
}
*/

    int lengthOfLIS(vector<int>& nums) {
        /*
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
        */
        /*
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int len=0+dp[ind+1][prev+1];
                if(prev==-1 || nums[ind]>nums[prev]){
                    len=max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][prev+1]=len;
            }
        }
        return dp[0][0];
        */        
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;         
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }
};
