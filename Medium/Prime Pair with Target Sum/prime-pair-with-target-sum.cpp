//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
  
  void seive( int n, vector< int >&allPrime )
  {
      vector< bool > flag( n + 1, true );
      
      flag[0] = false;
      
      flag[1] = false;
      
      for(int i = 2; i * i <= n; i++ )
      {
          if( flag[i] )
          {
              for( int j = 2 * i; j <= n; j = j + i )
              {
                  flag[j] = false;
              }
          }
      }
      
      for(int i = 0; i < flag.size(); i++ )
      {
          if( flag[i] == true )
          {
              allPrime.push_back( i );
          }
      }
  }
    vector<int> getPrimes(int n) {
        // code here
        vector< int > prime;
        
        seive( n, prime );
        
        int i = 0, j = prime.size() - 1;
        
        while( i <= j )
        {
            if( prime[i] + prime[j] == n )
            {
                return { prime[i] , prime[j] };
            }
            else if( prime[i] + prime[j] < n )
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return {-1, -1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends