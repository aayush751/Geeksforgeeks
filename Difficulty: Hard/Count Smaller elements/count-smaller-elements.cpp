//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
  
  int binarySearch( vector<int>&arr, int key )
  {
      int low = 0, high = arr.size();
      int mid = low + ( high - low ) / 2;
      while( low < high )
      {
          if( arr[mid] >= key )
          {
            //   ans = mid;
              high = mid;
          }
          else
          {
              low = mid + 1;
          }
          mid = low + ( high - low ) / 2;
      }
      
      
      if( low < arr.size() && arr[low] < key ) {
       low++;
    }
      return low;
  }
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int size = arr.size();
        vector<int> result(size);
        vector<int> temp;
        int k = size - 2;
        temp.push_back( arr[size - 1]);
        
        for(int i = size - 2; i > -1; i-- )
        {
            int index = binarySearch( temp, arr[i] );
            result[k--] = index;
            temp.insert( temp.begin() + index, arr[i] );
        }
        
        result[size - 1] = 0;
        return result;
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends