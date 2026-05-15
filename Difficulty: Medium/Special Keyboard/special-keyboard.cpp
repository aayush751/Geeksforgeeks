class Solution {
  public:
    int optimalKeys(int n) {
        // code here
        if (n <= 6) return n;

        // dp[i] will store the maximum number of 'A's possible with i keystrokes
        vector<int> dp(n + 1, 0);

        // Initialize the first 6 states
        for (int i = 1; i <= 6; ++i) {
            dp[i] = i;
        }

        // Calculate maximums for keystrokes from 7 to n
        for (int i = 7; i <= n; ++i) {
            // Option 1: Just press 'A'
            dp[i] = dp[i - 1] + 1;

            // Option 2: Find the best point in the past to perform Ctrl-A, Ctrl-C, 
            // followed by multiple Ctrl-Vs.
            // j represents the number of keystrokes dedicated to the copy-paste action.
            for (int j = 3; j < i; ++j) {
                dp[i] = max(dp[i], dp[i - j] * (j - 1));
            }
        }

        return dp[n];
    }
};