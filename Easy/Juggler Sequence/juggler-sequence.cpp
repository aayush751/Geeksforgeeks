//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    long long sqrts( long long n )
    {
        long long low = 0, high = n; 
        long long mid = low + ( high - low ) / 2;
        long long ans = 0;
        while( low <= high )
        {
            if( mid * mid <= n )
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            mid = low + ( high - low ) / 2;
        }
        
        return ans;
    }
    
    long long c_root( long long n )
    {
        return n * n * n;
    }
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector< long long > res;
        res.push_back( n );
        while( n != 1 )
        {
            if( n % 2 == 0 )
            {
                res.push_back( sqrt(n) );
            }
            else
            {
                res.push_back(sqrt(pow(n,3)));
            }
            n = res.back();
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends