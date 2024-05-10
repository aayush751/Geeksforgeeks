//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long sqrts( long long N )
    {
        long long s = 0, e = N;
        long long mid = s + ( e - s ) / 2;
        
        long long ans = 0;
        while( s <= e )
        {
            if( mid * mid == N )
            {
                ans = mid;
                e = mid - 1;
            }
            else if( mid * mid > N )
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            
            mid = s + ( e - s ) / 2;
        }
        return ans;
    }
    int isPerfectNumber(long long N) {
        // code here
        if( N == 1 )
        {
            return 0;
        }
        long long sum = 1;
        for(long long i = 2; i * i <= N; i++ )
        {
            if( N % i == 0 )
            {
                sum += i + N/i;
            }
        }
        
        return sum == N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends