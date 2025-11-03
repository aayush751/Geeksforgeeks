/**
 * @param {number} V
 * @param {number[][]} edges
 * @returns {number[]}
 */

class Solution {
    safeNodes(V, edges) {
        // Code here
        const adj = new Array(V).fill(0).map(() => []);
    const inDegree = new Array(V).fill(0);

    for (const [u, v] of edges) {
      adj[v].push(u);
      inDegree[u]++;
    }

    const queue = [];
    for (let i = 0; i < V; i++) {
      if (inDegree[i] === 0) {
        queue.push(i);
      }
    }

    const safe = new Array(V).fill(false);

    while (queue.length > 0) {
      const node = queue.shift();
      safe[node] = true;

      for (const neighbor of adj[node]) {
        inDegree[neighbor]--;
        if (inDegree[neighbor] === 0) {
          queue.push(neighbor);
        }
      }
    }

    const result = [];
    for (let i = 0; i < V; i++) {
      if (safe[i]) {
        result.push(i);
      }
    }

    return result;
    }
}
