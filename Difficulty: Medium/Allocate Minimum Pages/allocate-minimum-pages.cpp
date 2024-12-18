//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool solve( vector<int> &arr, int k, int mid )
    {
        int st_count = 1;
        int pageSum = 0;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            pageSum += arr[i];
            
            if( pageSum <= mid )
            {
                continue;
            }
            else
            {
                st_count++;
                
                if( st_count > k or arr[i] > mid )
                {
                    return false;
                }
                
                pageSum = arr[i];
            }
        }
        
        return true;
    }
    
    int iSsum( vector< int >& arr )
    {
        int sum = 0;
        
        for( int &num: arr )
        {
            sum += num;
        }
        
        return sum;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if( k > n )
        {
            return -1;
        }
        
        int sum = iSsum( arr );
        
        int l = 0, r = sum;
        
        int result = 0;
        
        while( l <= r )
        {
            int mid = l + ( r - l ) / 2;
            
            if( solve( arr, k, mid ) == 1 )
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends