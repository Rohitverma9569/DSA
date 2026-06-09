class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxi = *max_element(nums.begin(), nums.end());
        long long mini = *min_element(nums.begin(),nums.end());
        
        long long  ele=maxi-mini;
        long long ans=k*ele;
        return ans;
           
    }
};