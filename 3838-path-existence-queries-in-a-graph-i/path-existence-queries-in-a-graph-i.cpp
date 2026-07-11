class Solution {
public:
/*
    bool dfs(int curr, int target, unordered_map<int,vector<int>> &adj, vector<bool>& visited){
        if(curr==target){
            return true;
        }
        visited[curr]=true;
        for(int& ngbr:adj[curr]){
            if(!visited[ngbr]){
                if(dfs(ngbr,target,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    */
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        /*
          unordered_map<int,vector<int>>adj;
          for(int i=0;i+1<n;i++){
            if(nums[i+1]-nums[i] <= maxDiff){
                adj[i].push_back(i+1);
                adj[i+1].push_back(i);
            }
          }
          vector<bool> result;
          for(auto& query :queries){
            int u=query[0];
            int v=query[1];
            vector<bool> visited(n,false);
            result.push_back(dfs(u,v,adj,visited));
          }
          return result; 
          */
          vector<int> component(n, -1);
        int compId = 0;
        component[0] = compId;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] > maxDiff) {
                compId++;
            }
            component[i] = compId;
        }


        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(component[query[0]] == component[query[1]]);
        }
        return result;
    }
};