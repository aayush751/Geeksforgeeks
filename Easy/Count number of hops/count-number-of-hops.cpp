//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
const int mod = 1e9 + 7;
class Solution
{
    public:
    ll solve( vector< ll > &dp, int n )
    {
        if( n == 0 or n == 1 ) return 1;
        
        if( n == 2 ) return 2;
        
        if( dp[n] != -1 )
        {
            return dp[n];
        }
        
        ll ans = ( solve( dp, n - 1 ) % mod + solve( dp, n - 2 ) % mod + solve( dp, n - 3 ) % mod) % mod;
        
        dp[n] = ans;
        
        return dp[n];
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // base case
        vector< ll > dp( n + 1, -1 );
        return solve( dp, n );
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends