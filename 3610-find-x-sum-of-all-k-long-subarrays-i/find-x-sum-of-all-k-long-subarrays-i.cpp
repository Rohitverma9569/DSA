class Solution {
public:
static bool comp(vector<int>vec1,vector<int>vec2){
    if(vec1[1]==vec2[1]){
        return vec1[0]>vec2[0];
    }else{
        return vec1[1]>vec2[1];
    }
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        int j=k-1;
        while(j<n){
            unordered_map<int,int>mpp;
            for(int m=i;m<=j;m++){
                mpp[nums[m]]++; 
            }
            vector<vector<int>>vec;
            for(auto it:mpp){
                vec.push_back({it.first,it.second});
            }
            sort(vec.begin(),vec.end(),comp);
            int sum=0;
            for(int o=0;o<min(x, (int)vec.size());o++){
                sum=sum+vec[o][1]*vec[o][0];
            }
            ans.push_back(sum);
            i++;
            j++;  
        }
        return ans;
    }
};