//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s){
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) 
        {
            dp[i][i] = 1;  // hr ek single character tmhara palindrom hota hai
        }
    
        for (int len = 2; len <= n; len++) 
        {
            for (int i = 0; i <= n - len; i++) 
            {
                int j = i + len - 1;
                
                if (s[i] == s[j]) 
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } 
                else 
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    
        int lpsLength = dp[0][n - 1];
        
        return n - lpsLength;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends