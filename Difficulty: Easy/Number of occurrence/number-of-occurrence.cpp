//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int firstOccurence( vector< int >& arr, int key )
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        int ans = -1;
        
        while( l <= r )
        {
            int mid = l + ( r - l ) / 2;
            
            if( arr[mid] == key )
            {
                ans = mid;
                r = mid - 1;
            }
            else if( arr[mid] > key )
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return ans;
    }
    
    int lastOccurence( vector< int >& arr, int key )
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        int ans = -1;
        
        while( l <= r )
        {
            int mid = l + ( r - l ) / 2;
            
            if( arr[mid] == key )
            {
                ans = mid;
                l = mid + 1;
            }
            else if( arr[mid] > key )
            {
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }
        
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        // esme binary seacrh lgega
        
        int n = arr.size();
        int first = firstOccurence( arr, target );
        int last = lastOccurence( arr, target );
        
        if( first == -1 and last == -1 )
        {
            return 0;
        }
        
        return last - first + 1;
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends