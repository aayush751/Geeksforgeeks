//{ Driver Code Starts
// Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', _ => {
    inputString =
        inputString.trim().split('\n').map(string => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function buildTree(str) {
    // Corner Case
    if (str.length === 0 || str[0] === "N") return null;

    // Create the root of the tree
    let root = new Node(parseInt(str[0]));

    // Push the root to the queue
    let queue = [];
    let start = 0;
    queue.push(root);

    // Starting from the second element
    let i = 1;
    while (queue.length !== start && i < str.length) {

        // Get and remove the front of the queue
        let currNode = queue[start];
        start++;

        // Get the current node's value from the string
        let currVal = str[i];

        // If the left child is not null
        if (currVal !== "N") {

            // Create the left child for the current node
            currNode.left = new Node(parseInt(currVal));

            // Push it to the queue
            queue.push(currNode.left);
        }

        // For the right child
        i++;
        if (i >= str.length) break;
        currVal = str[i];

        // If the right child is not null
        if (currVal !== "N") {

            // Create the right child for the current node
            currNode.right = new Node(parseInt(currVal));

            // Push it to the queue
            queue.push(currNode.right);
        }
        i++;
    }

    return root;
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let input_ar1 = readLine().split(' ');
        let root = buildTree(input_ar1);
        let obj = new Solution();
        let res = obj.findSpiral(root);
        let s = '';
        for (let i = 0; i < res.length; i++) {
            s += res[i] + " ";
        }
        console.log(s);

        console.log("~");
    }
}
// } Driver Code Ends


/**
 * @param {Node} root
 * @returns {number[]}
 */
/*
class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
} */

class Solution {
    findSpiral(root) {
        // code here
         if (!root) return [];

    // Initialize the result array
    const result = [];

    // Use two stacks: one for even levels and one for odd levels
    let stackEven = [];
    let stackOdd = [];

    // Start with the root in the even level stack (level 0 is even)
    stackEven.push(root);

    // Track the current level (starting at 0)
    let currentLevel = 0;

    // Process nodes while either stack has elements
    while (stackEven.length > 0 || stackOdd.length > 0) {
      // Temporary array to hold current level's node values
      const currentLevelList = [];

      if (currentLevel % 2 === 0) {
        // Process even level: right to left
        while (stackEven.length > 0) {
          // Pop the last element from stackEven
          const node = stackEven.pop();
          // Add node's value to current level list
          currentLevelList.push(node.data);

          // Push right child first, then left to stackOdd (to ensure next level is left to right)
          if (node.right) stackOdd.push(node.right);
          if (node.left) stackOdd.push(node.left);
        }
      } else {
        // Process odd level: left to right
        while (stackOdd.length > 0) {
          // Pop the last element from stackOdd
          const node = stackOdd.pop();
          // Add node's value to current level list
          currentLevelList.push(node.data);

          // Push left child first, then right to stackEven (to ensure next level is right to left)
          if (node.left) stackEven.push(node.left);
          if (node.right) stackEven.push(node.right);
        }
      }

      // Add current level's values to the result array
      result.push(...currentLevelList);

      // Move to the next level
      currentLevel++;
    }

    // Return the final result array
    return result;
    }
}