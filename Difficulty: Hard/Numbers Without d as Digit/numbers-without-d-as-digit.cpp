class Solution {
  public:
  int dp[12][2][2];
  string numStr;
  int targetDigit;

  // Helper function for Digit DP
  int solveDP(int idx, bool tight, bool started) {
      if (idx == numStr.length()) {
          return started ? 1 : 0;
      }
      if (dp[idx][tight][started] != -1) {
          return dp[idx][tight][started];
      }

      int count = 0;
      int limit = tight ? (numStr[idx] - '0') : 9;

      for (int digit = 0; digit <= limit; ++digit) {
          // Skip digit if it matches d (except for leading zeros before the number starts)
          if (digit == targetDigit) {
              if (digit == 0 && !started) {
                  // Allowed as leading zero
              } else {
                  continue;
              }
          }

          bool nextTight = tight && (digit == limit);
          bool nextStarted = started || (digit > 0);

          count += solveDP(idx + 1, nextTight, nextStarted);
      }

      return dp[idx][tight][started] = count;
  }

  // Target Function with requested signature
  int countWithout(int n, int d) {
      if (n <= 0) return 0;
      numStr = to_string(n);
      targetDigit = d;
      memset(dp, -1, sizeof(dp));
      return solveDP(0, true, false);
  }
};