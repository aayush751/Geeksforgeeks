class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int totalSquares = n * m;

    // Total ways to choose 2 distinct squares for Black and White knights
    int totalWays = totalSquares * (totalSquares - 1);

    int attackingWays = 0;

    // Case 1: 2x3 blocks
    if (n >= 2 && m >= 3) {
        attackingWays += 4 * (n - 1) * (m - 2);
    }

    // Case 2: 3x2 blocks
    if (n >= 3 && m >= 2) {
        attackingWays += 4 * (n - 2) * (m - 1);
    }

    // Non-attacking ways = Total configurations - Attacking configurations
    return totalWays - attackingWays;
    }
};