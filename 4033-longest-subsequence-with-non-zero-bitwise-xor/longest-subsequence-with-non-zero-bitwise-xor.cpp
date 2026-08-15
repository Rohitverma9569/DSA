class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
         int n=nums.size();
       vector<int> arr=nums;
        if(n==1){
            if(nums[0]==0) return 0;
            else return 1;
        }
        int totalXor=0;
        bool d=false;
        for(int x : arr){
            totalXor^=x;
            if(x!=0) d=true;
        }
        if(totalXor!=0 && d){
            return n;
        }else if(totalXor==0 && !d){
            return 0;
        }
            else{
            return n-1;
            }
            
        
        
        
        
    
        
    }
};