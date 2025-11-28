class Solution {
  public:
  
  int xor1ton(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; // n % 4 == 3
}
    vector<int> subsetXOR(int n) {
        // code here
            int total = xor1ton(n);
    int x = total ^ n;   // The number to remove

    vector<int> ans;

    if (x >= 1 && x <= n) {
        // Best case: remove x
        for (int i = 1; i <= n; i++) {
            if (i != x) ans.push_back(i);
        }
    } else {
        // Fallback case: use all numbers
        // (this case happens rarely, but is valid)
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
        }
    }
    
    return ans;
    }
};
