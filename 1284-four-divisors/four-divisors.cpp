class Solution {
public:
pair<int,int> divisor(int num) {
    int div = 0;
    int sum = 0;

    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            div++;
            sum += i;

            if(i != num / i) {
                div++;
                sum += num / i;
            }

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