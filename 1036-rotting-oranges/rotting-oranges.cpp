class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        int maxTime=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int t=it.second;
            maxTime=max(maxTime,t);
            for(int i=0;i<4;i++){
                int drow=r+dx[i];
                int dcol=c+dy[i];
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && !visited[drow][dcol] && grid[drow][dcol]==1){
                    visited[drow][dcol]=1;
                    q.push({{drow,dcol},t+1});
                }

            }



        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=1){
                    return -1;
                }
            }
        }
        return maxTime;

        
    }
};