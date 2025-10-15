class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        int i=0;
        int j=2*k-1;
        while(j<n){
            bool b1=true;
            bool b2=true;
            for(int m=i;m<i+k;m++){
                if(m==i) continue;
                else{
                    if(nums[m]>nums[m-1]){
                        continue;
                    }
                    else{
                        b1=false;
                        break;
                    }
                }
            }
            if(b1==true){
                for(int n=i+k;n<i+2*k;n++){
                if(n==i+k) continue;
                else{
                    if(nums[n]>nums[n-1]){
                        continue;
                    }
                    else{
                        b2=false;
                        break;
                    }
                }
              }


            }
            if(b1==true && b2==true){
                return true;
            }
            i++;
            j++;
        }
        return false;

        
    }
};