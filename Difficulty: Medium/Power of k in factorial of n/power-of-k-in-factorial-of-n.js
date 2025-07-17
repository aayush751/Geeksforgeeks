class Solution {
    maxKPower(n, k) {
        // code here
        let factors = new Map();
    let temp = k;
    for (let i = 2; i * i <= temp; i++) {
      while (temp % i === 0) {
        factors.set(i, (factors.get(i) || 0) + 1);
        temp = Math.floor(temp / i);
      }
    }
    if (temp > 1) {
      factors.set(temp, (factors.get(temp) || 0) + 1);
    }

    let ans = Infinity;
    for (let [p, exp] of factors) {
      let count = 0;
      let power = p;
      while (power <= n) {
        count += Math.floor(n / power);
        power *= p;
      }
      let candidate = Math.floor(count / exp);
      if (candidate < ans) {
        ans = candidate;
      }
    }
    return ans;
    }
}