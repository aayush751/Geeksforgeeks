//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int carry = 1;
        reverse( begin(s), end(s) );
        
        for(int i = 0; i < s.size() and carry == 1; i++ )
        {
            if( s[i] == '0' )
            {
                s[i] = '1';
                carry = 0;
            }
            else
            {
                s[i] = '0';
                carry = 1;
            }
        }
        
        if( carry )
        {
            s = s + '1';
        }
        
        int idx = 0;
        
        reverse( begin(s), end(s) );
        
        while( s[idx] == '0' )
        {
            idx++;
        }
        
        return s.substr(idx, s.size() - idx );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends