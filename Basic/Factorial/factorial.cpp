//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    long long int solve( vector< long long int > &memo, int n )
    {
        // base case
        if( n ==  0 or n == 1 )
        {
            return 1;
        }
        
        if( memo[n] != -1 )
        {
            return memo[n];
        }
        
        memo[n] = n * solve( memo, n - 1 );
        
        return memo[n];
    }
    
    
    long long int factorial(int N){
        //code here
        vector< long long int > memo( N + 1, -1 );
        return solve( memo, N );
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends