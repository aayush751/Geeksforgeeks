/**
 * @param {string} s1
 * @param {string} s2
 * @returns {number}
 */

class Solution {
    minSuperSeq(s1, s2) {
        // code here
         const m = s1.length;
    const n = s2.length;

    let prev = new Array(n + 1).fill(0);
    let curr = new Array(n + 1).fill(0);

    for (let i = 1; i <= m; i++) {
      for (let j = 1; j <= n; j++) {
        if (s1[i - 1] === s2[j - 1]) {
          curr[j] = 1 + prev[j - 1];
        } else {
          curr[j] = Math.max(prev[j], curr[j - 1]);
        }
      }
      [prev, curr] = [curr, prev];
    }

    const lcsLength = prev[n];

    return m + n - lcsLength;
    }
}