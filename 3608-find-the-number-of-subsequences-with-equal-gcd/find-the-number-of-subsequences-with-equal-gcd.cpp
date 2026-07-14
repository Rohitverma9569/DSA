class Solution {
public:
int dp[201][201][201];
int mod=1e9+7;
    int solve(vector<int>& nums, int i, int first, int second){
        if(i==nums.size()){
            bool bothNotEmpty= (first!=0 && second!=0);
            bool  gcdMatch= (first==second);
            return (bothNotEmpty && gcdMatch)?1:0;
        }
        if(dp[i][first][second]!=-1){
            return dp[i][first][second];                
        }
        int skip=solve(nums,i+1,first,second);
        int firstTake=solve(nums,i+1,__gcd(first,nums[i]),second);
        int secondTake= solve(nums, i+1, first, __gcd(second,nums[i]));
        return dp[i][first][second]=(0LL+ skip + firstTake + secondTake)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
       int n=nums.size();
       memset(dp,-1,sizeof(dp));
       return solve(nums,0,0,0);      
    }
};