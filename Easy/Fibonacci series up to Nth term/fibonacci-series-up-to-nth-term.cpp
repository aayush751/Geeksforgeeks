//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector< int > ans;
        
        ans.push_back( 0 );
        ans.push_back( 1 );
        
        int mode = 1e9 + 7;
        
        int curr = 1, next = 0, prev = 0;
        
        while( n > 1 )
        {
            next = (curr + prev) % mode;
            prev = curr;
            ans.push_back( next );
            curr = next;
            n--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends