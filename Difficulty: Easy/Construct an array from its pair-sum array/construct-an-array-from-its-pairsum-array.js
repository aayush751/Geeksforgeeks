class Solution {
    constructArr(arr) {
        // code here
            const m = arr.length;

    if (m === 1) {
      return [1, arr[0] - 1];
    }

    const n = Math.floor((1 + Math.sqrt(1 + 8 * m)) / 2);

    const res = new Array(n);

    res[0] = Math.floor((arr[0] + arr[1] - arr[n - 1]) / 2);

    for (let i = 1; i < n; i++) {
      res[i] = arr[i - 1] - res[0];
    }

    return res;
    }
}