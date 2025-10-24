class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
          unordered_map<int, int> count, end;
    for (int num : arr) count[num]++;

    for (int num : arr) {
        if (count[num] == 0) continue;

        // Try to extend a previous subsequence
        if (end[num - 1] > 0) {
            end[num - 1]--;
            end[num]++;
            count[num]--;
        }
        // Try to start a new subsequence of at least length k
        else {
            bool canStart = true;
            for (int j = 0; j < k; j++) {
                if (count[num + j] <= 0) {
                    canStart = false;
                    break;
                }
            }
            if (!canStart) return false;

            // Use up the k numbers
            for (int j = 0; j < k; j++) count[num + j]--;
            end[num + k - 1]++;
        }
    }

    return true;
    }
};
