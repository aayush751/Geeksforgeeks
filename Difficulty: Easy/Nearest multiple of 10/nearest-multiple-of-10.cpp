//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string num_str) {
        // Complete the function
        int len = num_str.size();
    if (len == 0) return "0";

    // Find last digit
    int last_digit = num_str[len - 1] - '0';
    string rounded_str = num_str.substr(0, len - 1); // Remove the last digit
    
    // Round based on the last digit
    if (last_digit > 5) {
        int carry = 1;
        for (int i = rounded_str.size() - 1; i >= 0 && carry; i--) {
            if (rounded_str[i] == '9') {
                rounded_str[i] = '0';
            } else {
                rounded_str[i] += 1;
                carry = 0;
            }
        }
        if (carry) {
            rounded_str = "1" + rounded_str;
        }
    }

    rounded_str += '0'; // Add the rounded digit
    return rounded_str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends