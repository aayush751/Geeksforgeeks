//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int cnt = 0;
        int idx = -1;
        
        for(int i = 0; i < a.size() - 1; i++ )
        {
            if( a[i] < a[i + 1] )
            {
                continue;
            }
            else
            {
                idx = i;
                break;
            }
        }
        
        
        return ( idx == -1 ) ? a[a.size() - 1 ] : a[idx];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends