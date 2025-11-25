class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<vector<pair<int,int>>> adj(n);
        int m=flights.size();
        for(int i=0;i<m;i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        q.push({0,{src,0}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k) continue;
            for(auto iter:adj[node]){
                int adjWeight=iter.first;
                int edW=iter.second;
                if(cost+edW<dist[adjWeight] && stop<=k){
                    dist[adjWeight]=cost+edW;
                    q.push({stop+1,{adjWeight,cost+edW}});
                }

            }

        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];


        
        

        
    }
};