//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int NGE( vector< int >& arr, int n, int start )
    {
        int value = arr[start];
        vector< int > res;
        for(int i = start; i < n; i++ )
        {
            if( arr[i] > value )
            {
                res.push_back( arr[i] );
            }
        }
        
        return res.size();
    }

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector< int > ans;
        int i = 0;
       while( queries-- )
       {
            int size = NGE( arr, n, indices[i] );
            ans.push_back( size );
            i++;
       }
       
       return ans;
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends