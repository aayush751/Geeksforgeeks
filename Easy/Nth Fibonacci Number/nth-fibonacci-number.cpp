//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int mod = 1000000007;
        if( n == 1 or n == 2 )
        {
            return 1;
        }
        
        n = n - 2;
        int next, curr = 1, prev = 1;
        
        while( n )
        {
            next = curr + prev % mod;
            prev = curr % mod;
            curr = next % mod;
            n--;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends