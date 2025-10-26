class Solution {
public:
bool solve(vector<int>& nums,int k,int mid){
    int n=nums.size();
    int part=1;
    int partSum=0;
    for(int i=0;i<n;i++){
        if((partSum+nums[i])<=mid){
            partSum+=nums[i];
        }
        else{
            part++;
            if(part>k) return false;
            partSum=nums[i];
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int low=*max_element(nums.begin(),nums.end());
        if(k==n) return low;
        int high=sum;
        int ans=-1;
       
        while(low<=high){
            int mid=(low+high)/2;
            
            if(solve(nums,k,mid)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
            
        }
        return low;
        
        
    }
};