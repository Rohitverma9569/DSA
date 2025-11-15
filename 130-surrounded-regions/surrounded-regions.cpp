class Solution {
public:
void traversal(vector<vector<char>>& board,vector<vector<int>>& visited){
int n=board.size();
int m=board[0].size();
queue<pair<int,int>>q;
for(int i=0;i<n;i++){
    if(board[i][0]=='O'){
        q.push({i,0});
        visited[i][0]=1;
    }
}
for(int i=0;i<n;i++){
    if(board[i][m-1]=='O'){
        q.push({i,m-1});
        visited[i][m-1]=1;
    }
}
for(int j=1;j<m-1;j++){
    if(board[0][j]=='O'){
        q.push({0,j});
        visited[0][j]=1;
    }
}
for(int j=0;j<m-1;j++){
    if(board[n-1][j]=='O'){
        q.push({n-1,j});
        visited[n-1][j]=1;
    }
}
while(!q.empty()){
    int i=q.front().first;
    int j=q.front().second;
    q.pop();
    vector<int> vecx={-1,0,1,0};
    vector<int> vecy={0,1,0,-1};
    for(int k=0;k<4;k++){
        int l=vecx[k]+i;
        int p=j+vecy[k];
        if( l>=0 && l<n && p>=0 && p<m && board[l][p]=='O' && !visited[l][p] ){
            q.push({l,p});
            visited[l][p]=1;
        }
    }
    
}

}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        traversal(board,visited);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';

                }
            }
        }
        
    }
};