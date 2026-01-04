class Solution {
public:
pair<int,int> divisor(int num) {
    int sum = 0;
    int div = 0;

    for(int i = 1; i <= num; i++) {
        if(num % i == 0) {
            div++;
            sum += i;
            if(div > 4) {
                return {-1, -1};
            }
        }
    }
    return {div, sum};
}

    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=divisor(nums[i]);
            int k=it.first;
            int m=it.second;
            if(k==4 && k!=-1){
                ans+=m;

            }
        }
        return ans;      
    }
};