//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
 
    #define ll long long int
    long long int floorSqrt(long long int n) {
        // Your code goes here
        ll start = 1, end = n;
        ll ans = 0;
        
        ll mid = start + ( end - start ) / 2;
        
        while( start <= end )
        {
            if( mid * mid <= n )
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + ( end - start ) / 2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends