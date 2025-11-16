class Solution {
public:
void traversal(vector<vector<int>>& board,vector<vector<int>>& visited){
    int n=board.size();
    int m=board[0].size();
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0){
               if(board[i][j]==1){
                visited[i][j]=1;
                q.push({i,j});
               }

            }
            if(j==m-1){
                if(board[i][j]==1){
                visited[i][j]=1;
                q.push({i,j});
               }

            }
            if(i==0 && j>0 && j<m-1){
                if(board[i][j]==1){
                visited[i][j]=1;
                q.push({i,j});
               }

            }
            if(i==n-1 && j>0 && j<m-1){
                if(board[i][j]==1){
                visited[i][j]=1;
                q.push({i,j});
               }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            vector<int>vecx={-1,0,1,0};
            vector<int>vecy={0,1,0,-1};
            for(int k=0;k<4;k++){
                int r=i+vecx[k];
                int s=j+vecy[k];
                if(r>0 && r<n-1 && s>0 && s<m-1 && board[r][s]==1 && !visited[r][s]){
                    q.push({r,s});
                    visited[r][s]=1;
                }
            }
        }

    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        traversal(grid,visited);
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                     ans++;
                }
            }
        }
        return ans;

        
    }
};