/**
 * @param {number[]} arr
 * @param {number} x
 * @returns {number}
 */

class Solution {
    countLessEqual(arr, x) {
        // code here
        const n = arr.length;

    // find pivot (minimum element index)

    let pivot = 0;
    let left = 0,
      right = n - 1;
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
      if (arr[mid] < arr[0]) {
        pivot = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    // helper function to find last index with value <= x in sorted array

    const findLastLessOrEqual = (start, end) => {
      let result = -1;
      while (start <= end) {
        const mid = Math.floor((start + end) / 2);
        if (arr[mid] <= x) {
          result = mid;
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
      return result;
    };

    // search in both halves

    const idx1 = findLastLessOrEqual(pivot, n - 1);
    const idx2 = findLastLessOrEqual(0, pivot - 1);

    let count = 0;
    if (idx1 !== -1) count += idx1 - pivot + 1;
    if (idx2 !== -1) count += idx2 + 1;

    return count;
    }
}