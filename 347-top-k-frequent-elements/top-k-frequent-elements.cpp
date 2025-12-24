class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int n=mpp.size(); 
        vector<vector<int>>vec;
        for(auto it:mpp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i=n-1;i>=n-k;i--){
            ans.push_back(vec[i][1]);
        }
        return ans;
        
    }
};