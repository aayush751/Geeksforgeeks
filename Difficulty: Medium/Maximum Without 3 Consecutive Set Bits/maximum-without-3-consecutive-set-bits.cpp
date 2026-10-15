class Solution {
  public:
    int maxValue(int n) {
        // code here
        for (int i = 29; i >= 0; --i) {
                    // Check if bits i+2, i+1, and i are all set (1)
                    if (((n >> (i + 2)) & 1) && 
                        ((n >> (i + 1)) & 1) && 
                        ((n >> i) & 1)) {

                        // Clear the least significant bit of the triplet (bit i)
                        n &= ~(1 << i);
                    }
                }
                return n;
    }
};