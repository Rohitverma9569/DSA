class Solution {
public:
int countPartitions(vector<int>& arr, int target,int sum,int ind){
    if(ind==0){
        if((sum+arr[0]==target || sum-arr[0]==target ) && arr[0]==0){
            return 2;
        }
        if((sum+arr[0]==target || sum-arr[0]==target ) && arr[0]!=0){
            return 1;
        }
        return 0;
    }
    int plusTake=countPartitions(arr,target,sum+arr[ind],ind-1);
    int minusTake=countPartitions(arr,target,sum-arr[ind],ind-1);
    return plusTake+minusTake;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(nums,target,0,n-1);       
    }
};