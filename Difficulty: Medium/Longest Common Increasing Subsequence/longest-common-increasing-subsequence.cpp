class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n = (int)a.size(), m = (int)b.size();
    if (n == 0 || m == 0) return 0;

    // dp[j] = length of LCIS that ends with b[j]
    vector<int> dp(m, 0);

    for (int i = 0; i < n; ++i) {
        int current = 0; // best LCIS length for this a[i] with elements < a[i]
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                // we can extend a subsequence that ended with value < a[i]
                if (current + 1 > dp[j]) dp[j] = current + 1;
            } else if (a[i] > b[j]) {
                // b[j] is a candidate to be predecessor of a[i]
                if (dp[j] > current) current = dp[j];
            }
            // if a[i] < b[j], do nothing
        }
    }

    // answer is max dp[j]
    return *max_element(dp.begin(), dp.end());
    }
};