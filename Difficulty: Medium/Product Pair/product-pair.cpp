class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_set<int> seen;

    for (int x : arr) {
        // Special case: handling target = 0
        if (target == 0) {
            // If current element is 0 and we've seen any other number, 
            // or if we've seen a 0 before, a product of 0 is possible.
            if (x == 0 && !seen.empty()) {
                return true;
            }
            if (x != 0 && seen.count(0)) {
                return true;
            }
        } 
        // General case: target is non-zero
        else if (x != 0 && target % x == 0) {
            int required = target / x;
            if (seen.count(required)) {
                return true;
            }
        }
        
        // Add the current element to the set
        seen.insert(x);
    }

    return false;
    }
};