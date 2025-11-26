class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            int x=it[0];
            int y=it[1];
            int cost=it[2];
            adj[x][y]=cost;
            adj[y][x]=cost;
        }
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX){
                        
                  adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                    
                        
                    }   
                }
            }
        }
        pair<int,int>ans={0,INT_MAX};
        for(int i=0;i<n;i++){
            int counter=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold){
                    counter++;
                }
            }
            if(counter<ans.second){
                ans.second=counter;
                ans.first=i;
            }else if(counter==ans.second){
                ans.first=i;
            }
        }
        return ans.first;

        
    }
};