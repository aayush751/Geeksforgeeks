class Solution {
  public:
    int count(int n, int m) {
        // code here
        const int MOD = 1e9 + 7;

    if (n <= 0 || m <= 0) return 0;
    if (n == 1) return m;

    // Step 1: Precompute divisors and multiples for each number in range [1, m]
    std::vector<std::vector<int>> divisors(m + 1);
    std::vector<std::vector<int>> multiples(m + 1);

    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) {
            // i is a divisor of j
            divisors[j].push_back(i);
            // j is a multiple of i
            multiples[i].push_back(j);
        }
    }

    // Step 2: Base case - length 1 array (1 way for each ending element j)
    std::vector<long long> dp_prev(m + 1, 1);
    std::vector<long long> dp_curr(m + 1, 0);

    // Step 3: DP Transitions from length 2 up to n
    for (int len = 2; len <= n; ++len) {
        for (int j = 1; j <= m; ++j) {
            long long sum = 0;

            // Add combinations ending with divisors of j
            for (int d : divisors[j]) {
                sum = (sum + dp_prev[d]) % MOD;
            }

            // Add combinations ending with multiples of j
            for (int mult : multiples[j]) {
                sum = (sum + dp_prev[mult]) % MOD;
            }

            // Subtract dp_prev[j] because j divides itself (counted twice)
            sum = (sum - dp_prev[j] + MOD) % MOD;

            dp_curr[j] = sum;
        }
        dp_prev = dp_curr;
    }

    // Step 4: Sum up the answers for all valid ending values at length n
    long long total_arrays = 0;
    for (int j = 1; j <= m; ++j) {
        total_arrays = (total_arrays + dp_prev[j]) % MOD;
    }

    return total_arrays;
    }
};