//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        
        const long long mod = 1e9 + 7;
        
        long long ans = 0;
        
        long long i = 1;
        
        long long pro = 1;
         
        long long sum = 0;
        
        
        long long chk = 1;
        
        while( n > 0 )
        {
            pro = 1;
            for(int j = 1; j <= i; j++ )
            {
                pro = ( pro * chk ) % mod;
                chk++;
            }
            
            sum = (sum + pro) % mod;
            
            i++;
            
            n--;
        }
        
        return sum % mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends