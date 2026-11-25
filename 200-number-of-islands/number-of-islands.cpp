class Solution {
public:
void bfs(vector<vector<char>>& grid, int i,int j, int n, int m,vector<vector<int>>& visited){
     queue<pair<int,int>>q;
     visited[i][j]=1;
     q.push({i,j});
     while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int k=0;k<=3;k++){
            int nrow=row+dx[k];
            int ncol=col+dy[k];
             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
             }

        }
        
     }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    bfs(grid,i,j,n,m,visited);
                }
            }
        }
        return count;      
    }
};