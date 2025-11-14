class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<tuple<int,int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        while(!q.empty()){
         auto t=q.front();
         int i=get<0>(t);
         int j=get<1>(t);
         ans[i][j]=get<2>(t);
        
         if(i+1<n && !visited[i+1][j]){
             q.push({i+1,j,ans[i][j]+1}); 
             visited[i+1][j]=1;
         }
         if(j+1<m && !visited[i][j+1]){
             q.push({i,j+1,ans[i][j]+1}); 
             visited[i][j+1]=1;
         }
         if(i-1>=0 && !visited[i-1][j]){
             q.push({i-1,j,ans[i][j]+1});
             visited[i-1][j]=1; 
         }
         if(j-1>=0 && !visited[i][j-1]){
             q.push({i,j-1,ans[i][j]+1}); 
             visited[i][j-1]=1;
         }
         q.pop();
        }
        return ans;    
    }
};