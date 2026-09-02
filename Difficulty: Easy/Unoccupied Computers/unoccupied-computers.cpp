class Solution {
  public:
    int solve(int n, string s) {
        // code here
        vector<int> state(26, 0); 

        int occupied = 0;
        int rejectedCount = 0;

        for (char c : s) {
            int idx = c - 'A';

            if (state[idx] == 0) {
                // Customer Arrival
                if (occupied < n) {
                    occupied++;
                    state[idx] = 1; // Assigned a computer
                } else {
                    rejectedCount++;
                    state[idx] = 2; // Rejected
                }
            } else if (state[idx] == 1) {
                // Customer Departure (Occupying a computer)
                occupied--;
            }
            // If state[idx] == 2, the rejected customer is leaving; no computer freed.
        }

        return rejectedCount;
    }
};
