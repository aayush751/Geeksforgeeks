//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    int solve( int n, vector< int >&memo, int mod )
    {
        // base case
        if( n <= 1 )
        {
            return n;
        }
        
        // memo[0] = 1;
        // memo[1] = 1;
        
        if( memo[n] != -1 )
        {
            return memo[n] % mod;
        }
        
        memo[n] = ( solve( n - 1 , memo, mod ) % mod + solve( n - 2, memo, mod ) % mod ) % mod;
        
        return memo[n];
    }
    int nthFibonacci(int n){
        // code here
        
        vector< int > memo( n + 1, -1 );
        return solve( n, memo, 1000000007 );
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends