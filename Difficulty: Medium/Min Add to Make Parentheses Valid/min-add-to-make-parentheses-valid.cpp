class Solution {
  public:
    int minParentheses(string& s) {
        // code here
         int count = 0;


        int prefix = 0;


        for (char c : s) {
            if (c == '(') {
                prefix++;
            } else if (prefix == 0) {
                count++;
            } else {
                prefix--;
            }
        }


        count += prefix;


        return count;
    }
};