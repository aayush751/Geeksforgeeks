class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        if (n == 0) return 1;
    if (n == 1) return 1;
    int prev2 = 1; // ways[0]
    int prev1 = 1; // ways[1]
    int curr = 0;
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
    }
};