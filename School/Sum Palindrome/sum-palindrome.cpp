//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    
    long long rev( long long n )
    {
        long long rev = 0;
        
        while( n > 0 )
        {
            int ld = n % 10;
            rev = rev * 10 + ld;
            n /= 10;
        }
        
        return rev;
    }
    
    
    bool chk_palindrome( long long n )
    {
        long long reversed = rev( n );
        return n == reversed;
    }
    // long long operation( long long n )
    // {
    //     long long temp = n;
    //     long long reverse = rev( n );
    //     // long long sum = reverse + temp;
    //     // bool chk = chk_palindrome( sum );
    //     return reverse;
    // }
    
    
    long long isSumPalindrome(long long n){
        // code here
        
        long long temp = n;
        
        int i = 5;
        
        for(int i = 0; i <= 5; i++)
        {
            if( chk_palindrome( temp ) )
            {
                return temp;
            }
            else
            {
                temp = temp + rev( temp );
            }
        }
        
        return -1;
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
        cout<<ob.isSumPalindrome(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends