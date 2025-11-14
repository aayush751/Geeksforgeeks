/**
 * @param {number[]} stones
 * @param {number} k
 * @return {number}
 */

class Solution {
    mergeStones(stones, k) {
        // code here
        const n = stones.length;

    if ((n - 1) % (k - 1) !== 0) {
      return -1;
    }

    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + stones[i];
    }

    const dp = new Array(n);
    for (let i = 0; i < n; i++) {
      dp[i] = new Array(n).fill(0);
    }

    for (let length = k; length <= n; length++) {
      for (let i = 0; i + length <= n; i++) {
        const j = i + length - 1;

        dp[i][j] = Infinity;

        for (let mid = i; mid < j; mid += k - 1) {
          dp[i][j] = Math.min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
        }

        if ((length - 1) % (k - 1) === 0) {
          dp[i][j] += prefix[j + 1] - prefix[i];
        }
      }
    }

    return dp[0][n - 1];
    }
}