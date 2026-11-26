class Solution {
public:
void dfs(int row,int col, vector<vector<char>>& board, vector<vector<int>>& visited){
    int n=board.size();
    int m=board[0].size();
    visited[row][col]=1;
    int delR[]={-1,1,0,0};
    int delC[]={0,0,-1,1};
    for(int i=0;i<4;i++){
        int nrow=row+delR[i];
        int ncol=col+delC[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
            dfs(nrow,ncol,board,visited);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(0,j,board,visited);
            }
            if(!visited[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,visited);
            }
        }
        for(int i=1;i<n-1;i++){

            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,board,visited);
            }
            if(!visited[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,visited);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};