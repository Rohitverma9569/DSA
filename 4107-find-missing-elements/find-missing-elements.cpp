class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int n=*min_element(nums.begin(),nums.end());
        int m=*max_element(nums.begin(),nums.end());
        unordered_set<int> st(begin(nums),end(nums));
        vector<int>ans;
        for(int i=n;i<=m;i++){
            if(st.find(i)!=st.end()){
                continue;
            }else{
                ans.push_back(i);
                
            }
        }
        return ans;
        
        
    }
};