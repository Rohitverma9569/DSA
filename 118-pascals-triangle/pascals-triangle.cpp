class Solution {
public:
vector<int> solve(int n){
    vector<int>nums;
    nums.push_back(1);
    int res=1;
    for(int i=1;i<n-1;i++){
        res=res*(n-i);
        res=res/i;
        nums.push_back(res);
    }
    if(n>1) nums.push_back(1);
    return nums;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(solve(i+1));
        }
        return ans;

        
    }
};