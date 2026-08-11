class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        for(int i=sum;i<=2000;i++){
            if(mpp.find(i)==mpp.end()){
                return i;
            }
        }
        return 0;


    }
};