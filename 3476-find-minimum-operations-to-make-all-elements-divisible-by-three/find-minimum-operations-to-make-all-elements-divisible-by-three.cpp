class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int minOp=0;
        for(int i=0;i<n;i++){
            int k=nums[i]%3;
            if(k==0){
                continue;
            }
            else if(k==1){
                
                minOp++;

            }
            else if(k==2){
                minOp++;
            }

        }
        return minOp;
        
    }
};