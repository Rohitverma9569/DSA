class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,int>>pq;
        pq.push({0,k-1});
        dist[k-1]=0;
        while(!pq.empty()){
            auto it=pq.front();
            int time=it.first;
            int node=it.second;
            pq.pop();
            for(auto it:adj[node]){
                int tar=it.first;
                int tim=it.second;
                if(time+tim<dist[tar]){
                    dist[tar]=time+tim;
                    pq.push({tim+time,tar});
                }
            }
        }
        int m=*max_element(dist.begin(),dist.end());
        if(m==INT_MAX){
            return -1;
        }
        return m;



        

        

        
    }
};