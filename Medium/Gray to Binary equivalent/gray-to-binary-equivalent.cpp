//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        // sbse phle diye gye decimal number ko binary string me convert krna hai.
        // n k hr ek bit ko 1 se and krwwana hai taki pata chl sake ki n ka ith bit kya hai zero ya one
        
        string binary_string = "";
        
        for(int i = 0; i <= 31; i++ )
        {
            if( n & ( 1 << i ) )
            {
                binary_string = '1' + binary_string;
            }
            else
            {
                binary_string = '0' + binary_string;
            }
        }
        
        // binary string bnne k baad jo use ka string hai usko legein...mtlb faltu ka trailing zeroes remove kr dengein
        
        int idx = 0;
        for(int i = 0; i < 32; i++ )
        {
            if( binary_string[i] == '1' )
            {
                idx = i;
                break;
            }
        }
        
        
        // substr ka parameter hota hai position and length of string. 
        binary_string = binary_string.substr( idx, 32 - idx );
        
        string grey = "";
        
        grey = grey + binary_string[0];
        
        int a = binary_string[0] - '0';
        
        for(int i = 1; i < binary_string.size(); i++ )
        {
            int x = binary_string[i] - '0';
            if( a ^ x )
            {
                grey = grey + '1';
                a  = 1;
            }
            else
            {
                grey = grey + '0';
                a = 0;
            }
        }
    
        int ans = 0;
        
        for(int i = 0; i < grey.size(); i++ )
        {
            ans = ans * 2 + grey[i] - '0';
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends