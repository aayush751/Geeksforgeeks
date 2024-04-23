//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        if( n == 1 or n == 2 )
        {
            return 1;
        }
        
        int next = 0, curr = 1, prev = 1;
        
        n = n - 2;
        int mod = 1000000007;
        while( n-- )
        {
            next = (curr + prev) % mod;
            prev = curr % mod;
            curr = next % mod;
        }
        
        return next % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends