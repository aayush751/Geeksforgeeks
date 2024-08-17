//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    #define ll long long int
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int totalProduct = 1;
        ll size = nums.size();
        vector< ll > ans( size );
        ll zeroCnt = count( nums.begin(), nums.end(), 0 );
        
        if( zeroCnt == 1 or zeroCnt == 0 )
        {
            for(auto i: nums )
            {
                if( i != 0 )
                {
                    totalProduct *= i;
                }
            }
        }
        else if( zeroCnt > 1 )
        {
            totalProduct = 0;
        }
        
        for(ll i = 0; i < size; i++ )
        {
            if( zeroCnt == 1 )
            {
                if( nums[i] == 0 )
                {
                    ans[i] = totalProduct;
                }
            }
            else if( zeroCnt == 0 )
            {
                ans[i] = totalProduct / nums[i];
            }
            else
            {
                return ans;
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends