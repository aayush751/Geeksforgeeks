class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        if (n < 0) return false;
    
    // 0 is a palindrome (0 in binary)
    if (n == 0) return true;

    unsigned int originalNumber = n;
    unsigned int temp = n;
    unsigned int reversedNumber = 0;

    while (temp > 0) {
        // Shift the reversed number left by 1 to make space
        reversedNumber <<= 1;
        
        // Add the least significant bit of temp to reversedNumber
        reversedNumber |= (temp & 1);
        
        // Shift temp right by 1 to process the next bit
        temp >>= 1;
    }

    // Compare the fully reversed binary number with the original
    return originalNumber == reversedNumber;
    }
};