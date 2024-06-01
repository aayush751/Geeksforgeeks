//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int x = 0, y = 0;
        unordered_map< char, int > mp;
        
        for( char ch: s )
        {
            mp[ch]++;
        }
        
        for(auto i: mp )
        {
            int position = i.first - 'a' + 1;
            
            int freq = i.second;
            
            if( position % 2 == 0 and freq % 2 == 0 )
            {
                x++;
            }
            else if( position % 2 == 1 and freq % 2 == 1 )
            {
                y++;
            }
        }
        
        if( ( x + y ) % 2 == 0 )
        {
            return "EVEN";
        }
        return "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends