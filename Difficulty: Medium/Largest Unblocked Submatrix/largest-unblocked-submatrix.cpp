class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // code here
         vector<int> blocked_rows;
    vector<int> blocked_cols;

    // Extract blocked rows and columns from the given arr
    for (int i = 0; i < k; ++i) {
        blocked_rows.push_back(arr[i][0]);
        blocked_cols.push_back(arr[i][1]);
    }

    // Sort to find the sequential gaps between blocked lines
    sort(blocked_rows.begin(), blocked_rows.end());
    sort(blocked_cols.begin(), blocked_cols.end());

    // Find the maximum consecutive unblocked rows
    long long max_row_gap = 0;
    int prev_r = 0; // Top boundary edge
    
    for (int r : blocked_rows) {
        max_row_gap = max(max_row_gap, (long long)(r - prev_r - 1));
        prev_r = r;
    }
    // Gap between the last blocked row and the bottom edge
    max_row_gap = max(max_row_gap, (long long)(n - prev_r));

    // Find the maximum consecutive unblocked columns
    long long max_col_gap = 0;
    int prev_c = 0; // Left boundary edge
    
    for (int c : blocked_cols) {
        max_col_gap = max(max_col_gap, (long long)(c - prev_c - 1));
        prev_c = c;
    }
    // Gap between the last blocked column and the right edge
    max_col_gap = max(max_col_gap, (long long)(m - prev_c));

    // Calculate the maximum continuous area
    long long max_area = max_row_gap * max_col_gap;

    // Cast back to int as per the required return type
    return (int)max_area;
    }
};