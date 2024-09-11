//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        // le rhe hain priority queue wo bhi min heap wla
        
        priority_queue< long long, vector< long long >,  greater<long long> > minHeap;
        
        long long cost = 0;
        
        for(auto i: arr )
        {
            minHeap.push( i );
        }
        
        while( minHeap.size() > 1 )
        {
            long long ropeOne = minHeap.top();
            minHeap.pop();
            
            long long ropeTwo = minHeap.top();
            minHeap.pop();
            
            minHeap.push( ropeOne + ropeTwo );
            
            cost += ropeOne + ropeTwo;
        }
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends