class Solution {
public:
void solve(vector<int>& candidates,int target,vector<int>& curr,int ind,vector<vector<int>>& ans){
    if(ind==0){
        if(target%candidates[0]==0){
            while(target){
                curr.push_back(candidates[0]);
                target-=candidates[0];
            }
            ans.push_back(curr);
            while (!curr.empty() &&
                       curr.back() == candidates[0]) {
                    curr.pop_back();
                }
            return;
        }
        if(target==0){
            ans.push_back(curr);
            return;
        }
        return;
    }
    //not take
    solve(candidates,target,curr,ind-1,ans);
    //take
    if(candidates[ind]<=target){
    curr.push_back(candidates[ind]);
    solve(candidates,target-candidates[ind],curr,ind,ans);
    curr.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>curr;
        solve(candidates,target,curr,n-1,ans);
        return ans;    
    }
};