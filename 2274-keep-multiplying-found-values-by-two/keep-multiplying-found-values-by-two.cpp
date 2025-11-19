class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
    int n=nums.size();
    int ans=original;
    bool isFound=false;
    for(int i=0;i<n;i++){
            if(nums[i]==original){
                isFound=true;
                ans=ans*2;
                break;
            }
        }

    while(isFound==true){
        bool flag=false;
        for(int i=0;i<n;i++){
            if(nums[i]==ans){
                ans=ans*2;
                flag=true;
                break;
            }
        }
        if(flag==true){
            isFound=true;
        }else{
            isFound=false;
        }
    }
    return ans;
    }
};