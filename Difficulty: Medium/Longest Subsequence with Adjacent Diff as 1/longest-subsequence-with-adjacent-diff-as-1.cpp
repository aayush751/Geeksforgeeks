class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        std::unordered_map<int, int> dp;
                int max_len = 0;

                for (int x : arr) {
                    int len_minus = dp.count(x - 1) ? dp[x - 1] : 0;
                    int len_plus = dp.count(x + 1) ? dp[x + 1] : 0;

                    dp[x] = std::max(len_minus, len_plus) + 1;
                    max_len = std::max(max_len, dp[x]);
                }

                return max_len;
    }
};