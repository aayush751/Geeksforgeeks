class Solution {
    
    
    private:
    // Helper function to check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
  public:
    bool palindromePair(vector<string>& arr) {
        // Code here
        unordered_map<string, int> freq;
        
        // Store frequencies of all words to handle duplicate strings
        for (const string& s : arr) {
            freq[s]++;
        }

        for (const string& word : arr) {
            int len = word.length();
            
            // Check all possible splits of the word into left and right parts
            for (int k = 0; k <= len; k++) {
                string left = word.substr(0, k);
                string right = word.substr(k);

                // Case 1: If 'left' is a palindrome, check if reverse of 'right' exists
                if (isPalindrome(left)) {
                    string rev_right = right;
                    reverse(rev_right.begin(), rev_right.end());

                    if (freq.count(rev_right)) {
                        // Ensure we don't just match the word with itself,
                        // unless it appears multiple times in the original array.
                        if (rev_right != word || freq[word] > 1) {
                            return true;
                        }
                    }
                }

                // Case 2: If 'right' is a palindrome, check if reverse of 'left' exists.
                // We use k > 0 to avoid double-counting the empty string split 
                // which is already handled by Case 1.
                if (k > 0 && isPalindrome(right)) {
                    string rev_left = left;
                    reverse(rev_left.begin(), rev_left.end());

                    if (freq.count(rev_left)) {
                        if (rev_left != word || freq[word] > 1) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};