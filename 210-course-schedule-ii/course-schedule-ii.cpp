class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        int k=prerequisites.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<k;i++){
             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                 indegree[it]++;
            }  
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<int>ans1;
        if(ans.size()==n){
            return ans;
        }else{
            return ans1;
        }
        
    }
};