/**
 * @param {number} n
 * @param {number[]} arr
 * @returns {number}
 */

class Solution {
    countValid(n, arr) {
        // code here
        let total = 9 * Math.pow(10, n - 1);
    let forbidden = new Set(arr);
    let k = 10 - forbidden.size;
    let k0 = k;
    if (!forbidden.has(0)) {
      k0 = k - 1;
    }
    let totalInvalid = k0 * Math.pow(k, n - 1);
    return total - totalInvalid;
    }
}