//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix) {
    // Your code goes here
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    for(int i = 0; i < m; i++ )
    {
        int j = 0, k = m - 1;
        
        while( j < k )
        {
            swap( matrix[j][i] , matrix[k][i] );
            j++;
            k--;
        }
    }
    
    
    for(int i = 0; i < m; i++ )
    {
        for(int j = 0; j < i; j++ )
        {
            swap( matrix[j][i], matrix[i][j] );
        }
    }
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends