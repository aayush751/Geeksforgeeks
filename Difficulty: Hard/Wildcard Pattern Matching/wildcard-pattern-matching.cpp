//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        int m = pattern.length();
        int n = str.length();

        // dp[i][j] will be true if first i characters in pattern match the first j characters in str
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Handle patterns with '*' at the start
        for (int i = 1; i <= m; ++i) {
            if (pattern[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            } else {
                break;
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        // The answer will be whether the entire pattern matches the entire string
        return dp[m][n] ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends