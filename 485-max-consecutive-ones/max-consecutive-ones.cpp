class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int l=0;
        int r=0;
        while(r<n){
            if(nums[r]==0){
                maxi=max(maxi,r-l);
                l=r+1;
            }
            else{
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
        
    }
};