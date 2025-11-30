/**
 * @param {string} s
 * @return {number}
 */
 
 
 
 
 class TrieNode {
  constructor() {
    this.children = new Array(26).fill(null);
  }
}

class Solution {
    countSubs(s) {
        // code here
        let count = 0;
    const root = new TrieNode();

    for (let i = 0; i < s.length; i++) {
      let current = root;

      for (let j = i; j < s.length; j++) {
        const index = s.charCodeAt(j) - 97;

        if (current.children[index] === null) {
          current.children[index] = new TrieNode();
          count++;
        }

        current = current.children[index];
      }
    }

    return count;
    }
}