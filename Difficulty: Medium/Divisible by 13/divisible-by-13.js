class Solution {
    divby13(s) {
        // code here
        let remainder = 0;
    for (let i = 0; i < s.length; i++) {
      let digit = parseInt(s[i]);
      remainder = (remainder * 10 + digit) % 13;
    }
    return remainder === 0;
    }
}