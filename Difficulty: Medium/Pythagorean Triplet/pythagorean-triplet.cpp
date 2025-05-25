class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
          int n = arr.size();
    if (n < 3) return false;

    unordered_set<long long> sqSet;

    // Insert all squares into the set
    for (int x : arr) {
        sqSet.insert(1LL * x * x);
    }

    // Try all pairs and check if their sum of squares exists in the set
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long a2 = 1LL * arr[i] * arr[i];
            long long b2 = 1LL * arr[j] * arr[j];
            long long c2 = a2 + b2;
            if (sqSet.find(c2) != sqSet.end()) {
                return true;
            }
        }
    }

    return false;
    }
};