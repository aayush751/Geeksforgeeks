//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd(int a, int b) 
	{ 
	    // code here
	    int ans;
	      while( a != 0 and b != 0 )
	      {
	          ( a > b ) ? a = a % b : b = b % a;
	      }
	      
	      ans = ( a == 0 ) ?  b : a;
	      
	      return ans;
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends