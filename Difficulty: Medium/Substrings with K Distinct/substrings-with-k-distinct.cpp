class Solution {
  public:
  
   int atMostK(string &s, int k) {
        int freq[26] = {0};
        int left = 0, distinct = 0;
        int res = 0;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            // count substrings ending at right
            res += (right - left + 1);
        }

        return res;
    }
    int countSubstr(string& s, int k) {
        // code here
        if (k == 0) return 0;
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};