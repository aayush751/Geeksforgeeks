//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        if( prices.empty() )
        {
            return 0;
        }
        
        int maxProfit = 0;
        int temp = prices[0];
        
        for(int i = 1; i < prices.size(); i++ )
        {
            if( temp < prices[i] )
            {
                maxProfit = max( maxProfit, prices[i] - temp );
            }
            else
            {
                temp = prices[i];
            }
        }
        
        return maxProfit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends