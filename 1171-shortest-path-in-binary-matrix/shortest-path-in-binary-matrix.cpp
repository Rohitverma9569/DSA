class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<
    tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>
> pq;
        if(grid[0][0]!=0) return -1;
        pq.push({1,0,0});
        vector<vector<int>>visited(n,vector<int>(n,0));

        while(!pq.empty()){
            auto it=pq.top();
            int nodex=get<1>(it);
            int nodey=get<2>(it);
            int dist=get<0>(it);
            pq.pop();
            if(nodex==n-1 && nodey==n-1){
                        return dist;
            }
            int drow[]={-1,-1,-1,0,1,1,1,0};
            int dcol[]={-1,0,1,1,1,0,-1,-1};
            for(int i=0;i<8;i++){
                int xcor=nodex+drow[i];
                int ycor=nodey+dcol[i];
                if(xcor>=0 && xcor<=n-1 && ycor>=0 && ycor<=n-1 && grid[xcor][ycor]==0 &&         visited[xcor][ycor]==0){
                    visited[xcor][ycor]=1;
                    pq.push({dist+1,xcor,ycor});
                }
            }


        }
        return -1;


          
        
    }
};