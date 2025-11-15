/**
 * @param {number} n
 * @param {number[]} cuts
 * @return {number}
 */
class Solution {
    minCutCost(n, cuts) {
        // code here
        cuts.push(0);
    cuts.push(n);

    cuts.sort((a, b) => a - b);

    const m = cuts.length;

    const dp = new Array(m);
    for (let i = 0; i < m; i++) {
      dp[i] = new Array(m).fill(0);
    }

    for (let l = 2; l < m; l++) {
      for (let i = 0; i < m - l; i++) {
        const j = i + l;
        dp[i][j] = Number.MAX_SAFE_INTEGER;

        for (let k = i + 1; k < j; k++) {
          const cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
          dp[i][j] = Math.min(dp[i][j], cost);
        }
      }
    }

    return dp[0][m - 1];
    }
}
