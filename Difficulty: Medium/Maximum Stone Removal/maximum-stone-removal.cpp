class DSU {
    unordered_map<int, int> parent;
public:
    int find(int x) {
        if (!parent.count(x))
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};





class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
         DSU dsu;
        for (auto& stone : stones) {
            // Use ~ to differentiate row and column
            dsu.unite(stone[0], ~(stone[1]));
        }
        unordered_map<int, int> islands;
        for (auto& stone : stones) {
            islands[dsu.find(stone[0])]++;
        }
        // max stones removed = total stones - number of islands
        return stones.size() - islands.size();
    }
};