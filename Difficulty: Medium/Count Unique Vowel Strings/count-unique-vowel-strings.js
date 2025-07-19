// @param {string}
// @return {number}
class Solution {
    vowelCount(s) {
        // code here
        const vowels = new Set(["a", "e", "i", "o", "u"]);
    const countMap = new Map();
    for (let char of s) {
      if (vowels.has(char)) {
        countMap.set(char, (countMap.get(char) || 0) + 1);
      }
    }
    const distinctCount = countMap.size;
    if (distinctCount === 0) {
      return 0;
    }
    let product = 1;
    for (let count of countMap.values()) {
      product *= count;
    }
    let fact = 1;
    for (let i = 1; i <= distinctCount; i++) {
      fact *= i;
    }
    return product * fact;
    }
}