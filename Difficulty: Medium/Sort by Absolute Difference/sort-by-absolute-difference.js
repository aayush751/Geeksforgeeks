/**
 * @param {number[]} arr
 * @param {number} x
 * @return {void}
 */

class Solution {
    rearrange(arr, x) {
        // code here
         arr.sort((a, b) => Math.abs(a - x) - Math.abs(b - x));
    }
}