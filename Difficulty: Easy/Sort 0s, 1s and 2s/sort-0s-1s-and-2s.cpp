//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int i = 0, mid = 0, j = n - 1;
        
        while( mid <= j )
        {
            int number = arr[mid];
            
            switch ( number )
            {
                case 0: swap( arr[i], arr[mid] );
                i++;
                mid++;
                break;
                
                case 1: mid++;
                break;
                
                case 2: swap( arr[j], arr[mid] );
                j--;
                break;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends