class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[0]==0) return 2;
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int j=i;
                int leftsum=0;
                int rightsum=0;
                while(j>=0){
                    leftsum+=nums[j];
                    j--;
                    
                }
                j=i+1;
                while(j<n){
                    rightsum+=nums[j];
                    j++;
                }
                if(leftsum==rightsum){
                    result+=2;

                }
                else if(abs(leftsum-rightsum)==1){
                    result+=1;
                }
            }
        }
        return result;
        
    }
};