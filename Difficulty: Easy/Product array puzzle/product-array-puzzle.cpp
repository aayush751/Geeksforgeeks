//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        int zeroCount = 0;
        
        for( int& ele: arr )
        {
            if( ele == 0 )
            {
                zeroCount++;
            }
        }
        
        vector< int > productArray( n , 0 );
        
        if( zeroCount > 1 ) return productArray;
        
        int totalProduct = 1;
        
        if( zeroCount == 0 )
        {
            for( int& ele: arr )
            {
                totalProduct *= ele;
            }
            
            for( int i = 0; i < n; i++ )
            {
                productArray[i] = totalProduct / arr[i];
            }
            
            return productArray;
        }
        
        if( zeroCount == 1 )
        {
            int zeroIndex = -1;
            for( int i = 0; i < n; i++ )
            {
                if( arr[i] != 0 )
                {
                    totalProduct *= arr[i];
                }
                else
                {
                    zeroIndex = i;
                }
            }
            
            productArray[zeroIndex] = totalProduct;
        }
        
        return productArray;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends