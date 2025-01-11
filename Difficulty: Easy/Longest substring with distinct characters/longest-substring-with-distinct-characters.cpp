//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        int left = 0;
        int maxLength = 0;
        
        unordered_set< char > st;
        
        for( int right = 0; right < n; right++ )
        {
            while( st.find( s[right] ) != st.end() )
            {
                st.erase( s[left] );
                ++left;
            }
            
            st.insert( s[right] );
            maxLength = max( maxLength, right - left + 1 );
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends