//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        
        if( k > arr.size() )
        {
            return {};
        }
        int n = arr.size();
        // int newSize = n - k + 1;
        int newIdx = 0;
        vector< int > ans;
        
        unordered_map< int, int > mp;
        
        int left = 0;
        int count = 0;
        
        for( int right = 0; right < n; right++ )
        {
            mp[arr[right]]++;
            
            count++;
            
            if( count == k )
            {
                int size = mp.size();
                ans.push_back( size );
                mp[arr[left]]--;
                
                if( mp[arr[left]] == 0 )
                {
                    mp.erase( arr[left] );
                }
                
                left++;
                count--;
            }
        }
        
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends