//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int binarySearch( vector<int> &arr, int low, int high, int key )
    {
        // int low = 0, high = arr.size() - 1;
        int mid = low + ( high - low ) / 2;
        
        while( low <= high )
        {
            if( arr[mid] > key )
            {
                high = mid - 1;
            }
            else if( arr[mid] == key )
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + ( high - low ) / 2;
        }
        
        return -1;
    }
    
    int pivot( vector<int> &arr )
    {
        int low = 0, high = arr.size() - 1;
        int mid = low + ( high - low ) / 2;
        
        while( low < high )
        {
            if( arr[0] <= arr[mid] )
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
            mid = low + ( high - low ) / 2;
        }
        
        return low;
    }
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size() - 1;
        int pivotIndex = pivot( arr );
        int result = 0;
        
        if( arr[0] <= key and key <= arr[pivotIndex - 1] )
        {
            return binarySearch( arr, 0, pivotIndex - 1, key );
        }
        else
        {
            return binarySearch( arr, pivotIndex, n, key );
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends