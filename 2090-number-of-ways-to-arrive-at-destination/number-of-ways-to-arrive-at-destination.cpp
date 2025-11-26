class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        long long mod = 1e9+7;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            long long cost = it.first;
            int node = it.second;

            if (cost > dist[node]) continue;

            for (auto &jt : adj[node]) {
                int nxt = jt.first;
                long long wt = jt.second;

                if (cost + wt < dist[nxt]) {
                    dist[nxt] = cost + wt;
                    ways[nxt] = ways[node];
                    pq.push({dist[nxt], nxt});
                }
                else if (cost + wt == dist[nxt]) {
                    ways[nxt] = (ways[nxt] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
