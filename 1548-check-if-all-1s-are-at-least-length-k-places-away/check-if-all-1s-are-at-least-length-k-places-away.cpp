class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        bool ones=false;
        int prevOne=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(ones==true){
                    int p=i-prevOne-1;
                    prevOne=i;
                    if(p>=k){
                        continue;
                    }else{
                        return false;
                    }

                }
                else{
                    ones=true;
                    prevOne=i;
                }


                
            }
        }
        return true;
        
    }
};