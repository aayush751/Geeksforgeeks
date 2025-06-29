class Solution {
  public:
  
  bool isPossible( vector<int>& arr, int k, int maxSumAllowed) {
    int subarrays = 1;
    int currentSum = 0;

    for (int num : arr) {
        if (currentSum + num > maxSumAllowed) {
            subarrays++;
            currentSum = num;
            if (subarrays > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}
  
    int splitArray(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());  // minimum possible max sum
    int high = 0;                                     // maximum possible max sum

    for (int num : arr) high += num;

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, k, mid)) {
            result = mid;        // try to minimize
            high = mid - 1;
        } else {
            low = mid + 1;       // need a bigger max sum
        }
    }

    return result;
    }
};