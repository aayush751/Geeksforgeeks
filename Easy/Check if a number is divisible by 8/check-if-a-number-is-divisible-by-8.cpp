//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        if( s.size() == 2 )
        {
            int ans = stoi(s);
            
            if( ans % 8 == 0 )
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if( s.size() == 1 )
        {
            int ans = ( s[0] - '0' );
            
            if( ans != 8 )
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            int k = 3;
            
            int i = s.size() - 1;
            
            int ori = 0;
            
            int power = 0;
            
            while( k > 0 )
            {
                int temp = ( s[i--] - '0' );
                ori = temp * pow( 10, power ) + ori;
                k--;
                power++;
            }
            
            
            if( ori % 8 == 0 )
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends