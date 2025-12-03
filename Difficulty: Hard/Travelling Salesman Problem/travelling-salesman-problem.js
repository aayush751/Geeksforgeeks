/**
 * @param {number[][]} cost
 * @returns {number}
 */

class Solution {
    tsp(cost) {
        // code here
        const n = cost.length;
    const INF = Number.MAX_SAFE_INTEGER;

    // dp[mask][i] = min cost
    const dp = Array(1 << n)
      .fill()
      .map(() => Array(n).fill(INF));

    dp[1][0] = 0;

    for (let mask = 1; mask < 1 << n; mask++) {
      for (let i = 0; i < n; i++) {
        if (!(mask & (1 << i))) continue;
        if (dp[mask][i] === INF) continue;

        for (let j = 0; j < n; j++) {
          if (mask & (1 << j)) continue;
          const newMask = mask | (1 << j);
          dp[newMask][j] = Math.min(dp[newMask][j], dp[mask][i] + cost[i][j]);
        }
      }
    }

    const allMask = (1 << n) - 1;
    let result = INF;

    for (let i = 0; i < n; i++) {
      if (dp[allMask][i] !== INF) {
        result = Math.min(result, dp[allMask][i] + cost[i][0]);
      }
    }

    return result;
    }
}
