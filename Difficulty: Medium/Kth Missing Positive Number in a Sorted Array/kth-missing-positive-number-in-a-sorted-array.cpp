// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        int l = 0, h = n - 1;
        
        while( l <= h )
        {
            int mid = l + ( h - l ) / 2;
            
            int missing = arr[mid] - ( mid + 1 );
            
            if( missing < k )
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        
        return l + k;
    }
};
