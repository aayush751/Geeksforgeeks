//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int n1 = s1.size();
        int n2 = s2.size();
        
        if( n1 < n2 )
        {
            s1 = string( n2 - n1, '0') + s1;
        }
        else
        {
            s2 = string( n1 - n2, '0' ) + s2;
        }
        
        int carry = 0;
        string result = "";
        
        for(int i = s1.size() - 1; i >= 0; i-- )
        {
            int bit1 = s1[i] - '0';
            int bit2 = s2[i] - '0';
            
            int sum = carry + bit1 + bit2;
            carry = sum / 2;
            result = char( sum % 2 + '0' ) + result;
        }
        
        if( carry )
        {
            result = '1' + result;
        }
        
        int pos = result.find_first_not_of( '0' );
        
        if( pos != string::npos )
        {
            return result.substr( pos );
        }
        
        return "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends