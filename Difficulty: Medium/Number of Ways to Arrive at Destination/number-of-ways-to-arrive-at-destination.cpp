class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
         vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        int mod = 1e9 + 7;

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if (dist[v] == d + w) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        return ways[V-1];
    }
};