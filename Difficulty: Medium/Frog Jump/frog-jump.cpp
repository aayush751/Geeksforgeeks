class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        // Code here
        if (n == 1) return 0;

    int prev = 0;              // dp[i-1]
    int prev2 = 0;             // dp[i-2]

    for (int i = 1; i < n; i++) {
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        int jumpTwo = INT_MAX;
        if (i > 1) jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int curr = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = curr;
    }

    return prev;
    }
};