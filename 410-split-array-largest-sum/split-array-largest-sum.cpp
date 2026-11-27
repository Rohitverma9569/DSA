class Solution {
public:
int solve(vector<int>& nums,int mid){
    int n=nums.size();
    int sum=nums[0];
    int stu=0;
    for(int i=1;i<n;i++){
        
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }else{
            sum=nums[i];
            stu++;
        }
    }
    return stu;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int low=*max_element(nums.begin(),nums.end());
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=solve(nums,mid);
            if(cnt>=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
        
        
    }
};