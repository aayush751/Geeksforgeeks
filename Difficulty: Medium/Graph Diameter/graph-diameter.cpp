class Solution {
  public:
  
  
  pair<int, int> bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Find the farthest node and its distance
    int farthestNode = start;
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
            farthestNode = i;
        }
    }
    return {farthestNode, maxDist};
}
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 1: BFS from any node (say 0) to find farthest node A
    pair<int, int> firstBFS = bfs(0, adj);

    // Step 2: BFS from node A to find farthest node B and distance
    pair<int, int> secondBFS = bfs(firstBFS.first, adj);

    // The distance between A and B is the diameter
    return secondBFS.second;
    }
};
