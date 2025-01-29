//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        double ans = b, odd = 1.0;
        long long power = e;
        // phle positive bnao number ko agr negative hai toh
        
        if( power < 0 )
        {
            power = -1 * power;
        }
        
        if( power == 0 and b != 0 )
        {
            return 1.0;
        }
        
        while( power > 1 )
        {
            if( power % 2 == 0 )
            {
                ans = ans * ans;
                power = power / 2;
            }
            else
            {
                odd = odd * ans;
                power--;
            }
        }
        
        if( e < 0 )
        {
            return (double)(1.0)/ (double)( ans * odd );
        }
        
        return ( ans * odd );
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends