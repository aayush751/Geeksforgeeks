class Solution {
  public:
  
  const int MOD = 1e9 + 7;

  // Helper function for modular exponentiation: (base^exp) % MOD
  long long power(long long base, long long exp) {
      long long res = 1;
      base %= MOD;
      while (exp > 0) {
          if (exp % 2 == 1) res = (res * base) % MOD;
          base = (base * base) % MOD;
          exp /= 2;
      }
      return res;
  }

  // Modular multiplicative inverse using Fermat's Little Theorem
  long long modInverse(long long n) {
      return power(n, MOD - 2);
  }
  
    int prefixStrings(int n) {
        // code here
        if (n <= 0) return 1;

        // Compute (2n)!
        long long num = 1;
        for (int i = 1; i <= 2 * n; i++) {
            num = (num * i) % MOD;
        }

        // Compute n!
        long long factN = 1;
        for (int i = 1; i <= n; i++) {
            factN = (factN * i) % MOD;
        }

        // Compute (n + 1)!
        long long factNPlus1 = (factN * (n + 1)) % MOD;

        // C_n = (2n)! * inv(n!) * inv((n + 1)!) % MOD
        long long ans = (num * modInverse(factN)) % MOD;
        ans = (ans * modInverse(factNPlus1)) % MOD;

        return ans;
    }
};