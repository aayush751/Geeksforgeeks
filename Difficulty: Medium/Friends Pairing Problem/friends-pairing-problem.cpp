class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        if (n <= 2) return n;

    const int MOD = 1e9 + 7;

    // Variables to track f(n-2) and f(n-1)
    long long prev2 = 1; // f(1)
    long long prev1 = 2; // f(2)
    long long current = 0;

    for (int i = 3; i <= n; ++i) {
        current = (prev1 + (i - 1) * prev2) % MOD;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
    }
};
