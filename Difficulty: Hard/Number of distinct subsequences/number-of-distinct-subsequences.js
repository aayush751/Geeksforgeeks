class Solution {
    distinctSubseq(str) {
        // code here
         const MOD = 1000000007;
    const n = str.length;

    let dp = 1;

    const last = new Array(26).fill(0);

    for (let i = 0; i < n; i++) {
      const index = str.charCodeAt(i) - "a".charCodeAt(0);
      const prev = dp;

      dp = (2 * dp - last[index] + MOD) % MOD;

      last[index] = prev;
    }
    return dp;
    }
}
