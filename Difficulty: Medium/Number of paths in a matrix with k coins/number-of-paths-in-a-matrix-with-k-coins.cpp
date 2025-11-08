class Solution {
  public:
    int helper(vector<vector<int>>& mat, int i, int j, int k, vector<vector<vector<int>>>& dp) {
    int n = mat.size();
    int m = mat[0].size();
    
    // Out of bounds
    if (i >= n || j >= m) return 0;
    // If coins go negative, no valid path
    if (k < 0) return 0;
    // Base case: reached bottom-right cell
    if (i == n - 1 && j == m - 1)
        return (k == mat[i][j]) ? 1 : 0;
    
    // If already computed
    if (dp[i][j][k] != -1) return dp[i][j][k];
    
    // Subtract current cell coins and move right or down
    int remaining = k - mat[i][j];
    int down = helper(mat, i + 1, j, remaining, dp);
    int right = helper(mat, i, j + 1, remaining, dp);
    
    return dp[i][j][k] = down + right;
}

int numberOfPath(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    
    // 3D DP table initialized with -1
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
    
    return helper(mat, 0, 0, k, dp);
}
};