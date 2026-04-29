class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size();
    
    // 1. Count the total number of 1s in the array
    int totalOnes = 0;
    for (int num : arr) {
        if (num == 1) {
            totalOnes++;
        }
    }
    
    // Edge case: If there are no 1s, return -1 as requested
    if (totalOnes == 0) {
        return -1;
    }
    
    // If the array has only one 1 or is entirely 1s, 0 swaps are needed
    if (totalOnes == 1 || totalOnes == n) {
        return 0;
    }
    
    // The size of our sliding window is exactly the total number of 1s
    int windowSize = totalOnes;
    
    // 2. Count the number of 1s in the initial window
    int currentOnes = 0;
    for (int i = 0; i < windowSize; i++) {
        if (arr[i] == 1) {
            currentOnes++;
        }
    }
    
    int maxOnesInWindow = currentOnes;
    
    // 3. Slide the window across the rest of the array
    for (int i = windowSize; i < n; i++) {
        // Add the new element entering the right side of the window
        if (arr[i] == 1) {
            currentOnes++;
        }
        // Remove the old element leaving the left side of the window
        if (arr[i - windowSize] == 1) {
            currentOnes--;
        }
        
        // Update the maximum number of 1s found in any window
        maxOnesInWindow = max(maxOnesInWindow, currentOnes);
    }
    
    // 4. Minimum swaps = Total 1s needed - Maximum 1s already present in the best window
    return windowSize - maxOnesInWindow;
    }
};