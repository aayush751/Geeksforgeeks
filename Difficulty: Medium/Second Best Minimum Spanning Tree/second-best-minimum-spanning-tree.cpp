
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx == ry) return false;
        if(rank[rx] > rank[ry]) parent[ry] = rx;
        else if(rank[rx] < rank[ry]) parent[rx] = ry;
        else parent[ry] = rx, rank[rx]++;
        return true;
    }
};


class Solution {
  public:
    int secondMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<tuple<int,int,int,int>> edgeList;
        for(int i = 0; i < edges.size(); i++)
            edgeList.push_back({edges[i][2], edges[i][0], edges[i][1], i});
        sort(edgeList.begin(), edgeList.end());
        
        // First, find MST
        DSU dsu(V);
        vector<int> mstEdges;
        int mstWeight = 0;
        for(auto& [w, u, v, idx] : edgeList) {
            if(dsu.unite(u, v)) {
                mstWeight += w;
                mstEdges.push_back(idx);
            }
        }
        if(mstEdges.size() != V-1) return -1; // No MST
        
        int secondBest = 1e9;
        // Try removing each edge from MST and find alt MST
        for(int skipIdx : mstEdges) {
            DSU dsu2(V);
            int weight = 0, cnt = 0;
            for(auto& [w, u, v, idx] : edgeList) {
                if(idx == skipIdx) continue;
                if(dsu2.unite(u, v)) {
                    weight += w;
                    cnt++;
                }
            }
            if(cnt == V-1 && weight > mstWeight)
                secondBest = min(secondBest, weight);
        }
        return (secondBest == 1e9) ? -1 : secondBest;
    }
};