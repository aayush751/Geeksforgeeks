//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        
        if( k > arr.size() )
        {
            k = arr.size();
        }
        
        priority_queue< int, vector< int >,  greater<int> > pq;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            if( pq.size() < k )
            {
                pq.push( arr[i] );
            }
            else if( arr[i] > pq.top() )
            {
                pq.pop();
                pq.push( arr[i] );
            }
        }
        
        int size = pq.size();
        
        vector< int > result( size, 0 );
        
        for(int i = size - 1; i >= 0; i-- )
        {
            result[i] = pq.top();
            pq.pop();
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends