/**
 * @param {number[]} arr
 * @param {number} k
 * @returns {number}
 */

class Solution {
    minSoldiers(arr, k) {
        // code here
        const n = arr.length;
    const required = Math.ceil(n / 2);
    const costs = [];
    for (let i = 0; i < n; i++) {
      const remainder = arr[i] % k;
      if (remainder === 0) {
        costs.push(0);
      } else {
        costs.push(k - remainder);
      }
    }
    costs.sort((a, b) => a - b);
    let total = 0;
    for (let i = 0; i < required; i++) {
      total += costs[i];
    }
    return total;
    }
}