//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToeplitz(vector<vector<int>>& mat) {
    // code here
     int n=mat.size();
    int m=mat[0].size();
    
    int i=0;
    int j=0;
    while(j<m){
        int x=0;
        int y=j;
        int val=mat[x][y];
        while(x<n and y<m){
            if(mat[x][y]!=val) return false;
            x++;
            y++;
        }
        j++;
    }
    
    i=1;
    while(i<n){
        int x=i;
        int y=0;
        int val=mat[x][y];
        while(x<n and y<m){
            if(mat[x][y]!=val) return false;
            x++;
            y++;
        }
        i++;
    }
    return true;
}