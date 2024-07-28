//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        vector< int > freq(26,0);
        for(auto ch: str )
        {
            freq[ch - 'a']++;
        }
        
        string result;
        
        for( int i = 0; i < str.size(); i++ )
        {
            if( freq[str[i] - 'a'] != 0 )
            {
                result += str[i];
                freq[str[i] - 'a'] = 0;
            }
        }
        
        return result;
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends