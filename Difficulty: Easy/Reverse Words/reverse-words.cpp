//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        istringstream as1( str );
        string s1;
        
        vector< string > ans;
        
        while( getline( as1, s1, '.'))
        {
            ans.push_back( s1 );
        }
        
        string result;
        
        for( int i = ans.size() - 1; i >= 0; i-- )
        {
            result += ans[i];
            
            if( i != 0 )
            {
                result += ".";
            }
        }
        
        // result.pop_back();
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends