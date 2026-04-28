class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        vector<int> count(26, 0); 
    
    int max_len = 0;   // Stores the length of the longest valid substring
    int max_count = 0; // Stores the count of the most frequent character in the window
    int left = 0;      // Left pointer of our sliding window

    for (int right = 0; right < s.length(); right++) {
        // 1. Add the new character to our window's frequency count
        count[s[right] - 'A']++;
        
        // 2. Update the highest frequency of any single character we've seen in the window
        max_count = max(max_count, count[s[right] - 'A']);

        // 3. Check if the current window is valid.
        // The number of characters we need to replace is the total window size 
        // minus the count of the most frequent character.
        // If this exceeds k, the window is invalid and we must shrink it.
        if (right - left + 1 - max_count > k) {
            count[s[left] - 'A']--;
            left++;
        }

        // 4. Update the maximum length found so far
        // Note: Because we only shrink the window by 1 when it's invalid (rather than 
        // shrinking it until it's valid), the window size never decreases. 
        // It only grows when we find a better valid substring.
        max_len = max(max_len, right - left + 1);
    }

    return max_len;
    }
};