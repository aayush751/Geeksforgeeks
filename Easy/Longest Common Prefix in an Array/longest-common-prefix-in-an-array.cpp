//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans;
        
        bool flag = false;
        
        
        if( N == 1 )
        {
            return arr[0];
        }
        
        for(int i = 0; i < arr[0].size(); i++ )
        {
            for(int j = 1; j < N; j++ )
            {
                if( arr[0][i] == arr[j][i] )
                {
                    continue;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            
            if( flag == true )
            {
                if( ans.size() != 0 )
                {
                    return ans;
                }
                else
                {
                    return "-1";
                }
            }
            
            ans = ans + arr[0][i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends