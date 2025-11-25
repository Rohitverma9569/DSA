class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,   greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int xt[]={-1,0,+1,0};
        int yt[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int xcor=it.second.first;
            int ycor=it.second.second; 
            pq.pop();
            if(xcor==n-1 && ycor==m-1) return dis;
            for(int i=0;i<4;i++){
                int row=xcor+xt[i];
                int col=ycor+yt[i];
                if(row>=0 && row<n && col>=0 && col<m){
                    int newEffort=max(abs(heights[xcor][ycor]-heights[row][col]),dis);
                    if(newEffort<dist[row][col]){
                        dist[row][col]=newEffort;
                        pq.push({newEffort,{row,col}});
                        
                    }
                }
            }
        }
        return 0;     
    }
};