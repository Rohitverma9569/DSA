class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int it:nums){
            mpp[it]++;
        }
        if(k==n){
            return *max_element(nums.begin(),nums.end());

        }
        if(k==1){
            int maxi=-1;
            for(auto it: mpp){
                if(it.second==1){
                    maxi=max(maxi,it.first);
                }
            }
            return maxi;

        }
        int m1=mpp[nums[0]];
        int m2=mpp[nums[n-1]];
        if(nums[0]==nums[n-1]){
            return -1;
        }
        if(m1==1 && m2==1){
            return max(nums[0],nums[n-1]);
        }else if(m1>1 && m2==1){
            
            return nums[n-1];
        }
        else if(m2>1 && m1==1){
            return nums[0];
        }
        else{
            return -1;
        }
        return 0;
        
    }
};