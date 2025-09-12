// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if( n == 1 )
        {
            return 0;
        }
        
        sort( arr.begin(), arr.end() );
        
        int ans = arr[n - 1] - arr[0];
        int small = 0, large = 0;
        
        for(int i = 1; i < n; i++ )
        {
            if( arr[i] - k < 0 )
            {
                continue;
            }
            
            small = min( arr[0] + k, arr[i] - k );
            large = max( arr[n - 1] - k, arr[i - 1] + k );
            
            ans = min( ans, large - small );
        }
        return ans;
    }
};
