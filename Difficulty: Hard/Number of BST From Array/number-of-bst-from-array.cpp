class Solution {
  public:
  
  vector<int> computeCatalan(int n) {
    vector<int> cat(n + 1, 0);
    cat[0] = cat[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cat[i] += cat[j] * cat[i - j - 1];
        }
    }
    return cat;
}
  
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
       int n = arr.size();
    vector<int> result(n);
    vector<int> catalan = computeCatalan(n);

    // Sort array to simulate BST ordering
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    // Map root value -> number of BSTs
    unordered_map<int, int> rootCount;
    for (int i = 0; i < n; i++) {
        int left = i;
        int right = n - i - 1;
        rootCount[sorted[i]] = catalan[left] * catalan[right];
    }

    // Return results in the same order as original array
    for (int i = 0; i < n; i++) {
        result[i] = rootCount[arr[i]];
    }

    return result;
    }
};