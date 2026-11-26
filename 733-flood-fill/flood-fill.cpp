class Solution {
public:
void solve(vector<vector<int>>& image, int sr, int sc, int color, int srcColor,vector<vector<int>>& visited){
    int n=image.size();
    int m=image[0].size();
    visited[sr][sc]=1;
    queue<pair<int,int>>q;
    q.push({sr,sc});
    image[sr][sc]=color;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,1,-1};
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        for(int i=0;i<4;i++){
         int rowx=row+dx[i];
         int coly=col+dy[i];
         if(rowx>=0 && rowx<n && coly>=0 && coly<m && !visited[rowx][coly] && image[rowx][coly]==srcColor){
            image[rowx][coly]=color;
            visited[rowx][coly]=1;
            q.push({rowx,coly});
         }        
       }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if (image[sr][sc] == color)
            return image;
        vector<vector<int>> visited(n,vector<int>(m,0));
        solve(image,sr,sc,color,image[sr][sc],visited);
        return image;


        
    }
};