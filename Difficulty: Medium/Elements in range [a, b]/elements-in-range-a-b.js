class Solution {
    cntInRange(arr, queries) {
        // code here
        arr.sort((a, b) => a - b);

    const result = [];

    // process each query

    for (const [a, b] of queries) {
      // find lower bound (first index where arr[i] >= a)

      let left = 0;
      let right = arr.length;
      while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] < a) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      const lowerBound = left;

      // find upper bound (first index where arr[i] > b)

      left = 0;
      right = arr.length;
      while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] <= b) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      const upperBound = left;

      // count elements in range [a, b]

      result.push(upperBound - lowerBound);
    }

    return result;
    }
}