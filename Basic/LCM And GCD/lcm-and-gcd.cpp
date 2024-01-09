//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long a , long long b ) {
        // code here
        long long pro = a * b;
        
        long long gcd = 0;
        
        long long lcm = 0;
        
        while( a != 0 and b != 0 )
        {
            ( a > b ) ? a =  a % b : b = b % a;
        }
        
        gcd = ( a == 0 ) ? b : a;
        
        lcm = pro / gcd;
        
        return { lcm, gcd} ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends