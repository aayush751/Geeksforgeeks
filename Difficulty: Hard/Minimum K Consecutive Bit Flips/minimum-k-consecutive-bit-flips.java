class Solution {
    public int kBitFlips(int[] arr, int k) {
        // code here
          Queue<Integer> q = new LinkedList<>();
    int res = 0;
    int n = arr.length;

    for (int i = 0; i < n; i++) {
        // Remove flips that are out of current window 
        while (!q.isEmpty() && i > q.peek() + k - 1) {
            q.poll();
        }
        
        // If bit is 0 after considering flips done so far, flip at i
        if ((arr[i] + q.size()) % 2 == 0) {
            if (i + k > n) return -1; // Can't flip past array length
            res++;
            q.add(i); // Add this flip start index to queue
        }
    }
    return res;
    }
}
