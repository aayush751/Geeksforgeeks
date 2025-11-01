class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
         vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    // Build graph and indegree array
    for (auto& pre : prerequisites) {
        int x = pre[0], y = pre[1];
        adj[y].push_back(x);
        indegree[x]++;
    }

    // Queue for courses with no prerequisites
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> order;

    // Process courses
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);

        // Reduce indegree of dependent courses
        for (int next : adj[course]) {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    // If all courses are taken, return the order
    if (order.size() == n)
        return order;

    // Cycle detected → impossible to finish all
    return {};
    }
};