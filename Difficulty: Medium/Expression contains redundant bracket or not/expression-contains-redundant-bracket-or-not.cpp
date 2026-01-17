class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
         stack<char> st;

        for (char ch : s) {
            // Push everything except ')'
            if (ch != ')') {
                st.push(ch);
            } 
            else {
                bool hasOperator = false;

                // Pop until '('
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();

                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }

                // Remove '('
                if (!st.empty())
                    st.pop();

                // No operator inside parentheses → redundant
                if (!hasOperator)
                    return true;
            }
        }
        return false;
    }
};
