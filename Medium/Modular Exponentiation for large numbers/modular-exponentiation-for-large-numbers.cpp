//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if( x == 0 )
		    {
		        return 0;
		    }
		    
		    if( n == 1 )
		    {
		        return x % M;
		    }
		    
		    if( n % 2 == 0 )
		    {
		        long long ans = PowMod( x, n / 2, M );
		        return (ans % M * ans % M) % M;
		    }
		    else
		    {
		        long long ans = PowMod(x, ( n - 1 ) / 2, M );
		        return (ans % M * ans % M * x % M) % M;
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends