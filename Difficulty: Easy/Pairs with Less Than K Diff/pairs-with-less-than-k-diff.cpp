class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        if (k <= 0) return 0;

    int n = arr.size();
    
    // Step 1: Sort the array
    std::sort(arr.begin(), arr.end());

    int count = 0;
    int right = 0;

    // Step 2: Two-pointer sliding window
    for (int i = 0; i < n; ++i) {
        // Expand right pointer while the difference is strictly less than k
        while (right < n && arr[right] - arr[i] < k) {
            right++;
        }

        // Count all valid indices j > i
        if (right > i) {
            count += (right - 1 - i);
        }
    }

    return count;
    }
};