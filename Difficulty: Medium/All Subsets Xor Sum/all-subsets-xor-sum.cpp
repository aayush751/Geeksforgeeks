class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
         int n = arr.size();
    // If array is empty, sum is zero
    if (n == 0) return 0;

    // Compute OR of all elements
    // Because each bit that appears in the OR contributes equally
    int OR = 0;
    for (int x : arr) OR |= x;

    // Total subsets = 2^n
    // Each bit contributes in exactly half of them = 2^(n-1)
    long long result = (long long) OR * (1LL << (n - 1));

    return (int)result; 
    }
};