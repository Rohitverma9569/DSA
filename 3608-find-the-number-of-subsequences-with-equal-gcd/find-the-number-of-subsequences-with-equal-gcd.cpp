class Solution {
public:

int dp[201][201][201];
int mod=1e9+7;
 /*
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
 */
    int subsequencePairCount(vector<int>& nums) {
       int n=nums.size();
       //memset(dp,0,sizeof(dp));
       int maxEl= *max_element(nums.begin(),nums.end());
       int dp[n+1][maxEl+1][maxEl+1];
       for(int first=0;first<=maxEl;first++){
        for(int second=0;second<=maxEl;second++){
            bool bothNonEmpty=(first!=0 && second!=0);
            bool gcdMatch=(first==second);
            dp[n][first][second]=(bothNonEmpty && gcdMatch)?1:0;
        }
       }
       for(int i=n-1;i>=0;i--){
        for(int first=maxEl;first>=0;first--){
            for(int second=maxEl;second>=0;second--){
                int skip=dp[i+1][first][second];

                int take1=dp[i+1][__gcd(first,nums[i])][second];


                int take2=dp[i+1][first][__gcd(second,nums[i])];
                dp[i][first][second]=(0LL+skip+take1+take2)%mod;
            }
        }
       }
       return dp[0][0][0];     
    }
};