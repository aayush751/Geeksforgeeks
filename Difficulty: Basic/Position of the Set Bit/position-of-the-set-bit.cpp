class Solution {
  public:
    int findPosition(int n) {
        // code here
        if (n <= 0 || (n & (n - 1)) != 0) {
        return -1;
    }

    // 2. Find the position of that single set bit.
    int position = 1;
    
    // While the least significant bit (LSB) is 0, keep shifting right.
    while ((n & 1) == 0) {
        n = n >> 1;
        position++;
    }

    return position;
    }
};