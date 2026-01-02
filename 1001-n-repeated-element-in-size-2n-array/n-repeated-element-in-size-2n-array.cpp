class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()){
                return nums[i];
                break;

            }else{
                mpp[nums[i]]++;
            }
        }
        return 0;
        
        
    }
};