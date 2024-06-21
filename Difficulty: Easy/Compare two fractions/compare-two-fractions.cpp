//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        long a = 0, b = 0, c = 0, d = 0;
        
        sscanf(str.c_str(), "%ld/%ld,%ld/%ld", &a, &b, &c, &d);
        
         long lhs = a * d; // Left-hand side of comparison (a/b) * (d/d)
        long rhs = c * b; // Right-hand side of comparison (c/d) * (b/b)

        // Compare the cross-multiplied results
        if (lhs == rhs) {
            return "equal";
        } else if (lhs > rhs) {
            return to_string(a) + '/' + to_string(b);
        } else {
            return to_string(c) + '/' + to_string(d);
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends