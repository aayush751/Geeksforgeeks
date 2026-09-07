class Solution {
  public:
    int minCount(vector<int>& arr) {
        // code here
        int n = arr.size();
                if (n <= 1) return 0;

                // dp[i + 1][j + 1] stores max elements included where:
                // INC ends at index i (-1 <= i < n)
                // DEC ends at index j (-1 <= j < n)
                std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
                dp[0][0] = 0; // Base case: both INC and DEC are empty

                int max_used = 0;

                for (int k = 0; k < n; ++k) {
                    // Collect valid previous INC endpoints (i < k)
                    std::vector<int> valid_INC;
                    valid_INC.push_back(0); // i = -1
                    for (int i = 0; i < k; ++i) {
                        if (arr[i] < arr[k]) {
                            valid_INC.push_back(i + 1);
                        }
                    }

                    // Collect valid previous DEC endpoints (j < k)
                    std::vector<int> valid_DEC;
                    valid_DEC.push_back(0); // j = -1
                    for (int j = 0; j < k; ++j) {
                        if (arr[j] > arr[k]) {
                            valid_DEC.push_back(j + 1);
                        }
                    }

                    int k_mapped = k + 1;

                    // 1. Try appending arr[k] to INC
                    for (int j = 0; j <= k; ++j) {
                        int best_prev = -1;
                        for (int i_idx : valid_INC) {
                            if (dp[i_idx][j] > best_prev) {
                                best_prev = dp[i_idx][j];
                            }
                        }
                        if (best_prev != -1) {
                            dp[k_mapped][j] = best_prev + 1;
                            max_used = std::max(max_used, dp[k_mapped][j]);
                        }
                    }

                    // 2. Try appending arr[k] to DEC
                    for (int i = 0; i <= k; ++i) {
                        int best_prev = -1;
                        for (int j_idx : valid_DEC) {
                            if (dp[i][j_idx] > best_prev) {
                                best_prev = dp[i][j_idx];
                            }
                        }
                        if (best_prev != -1) {
                            dp[i][k_mapped] = best_prev + 1;
                            max_used = std::max(max_used, dp[i][k_mapped]);
                        }
                    }
                }

                return n - max_used;
    }
};