//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        
        if( s1.size() != s2.size() )
        {
            return false;
        }
        
        vector< int > freq(26, 0);
        
        for( size_t i = 0; i < s1.size(); i++ )
        {
            freq[s1[i] - 'a']++;
        }
        
        for( size_t i = 0; i < s2.size(); i++ )
        {
            if( freq[s2[i] - 'a'] > 0 )
            {
                freq[s2[i] - 'a']--;
            }
        }
        
        for( size_t i = 0; i < freq.size(); i++ )
        {
            if( freq[i] != 0 )
            {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends