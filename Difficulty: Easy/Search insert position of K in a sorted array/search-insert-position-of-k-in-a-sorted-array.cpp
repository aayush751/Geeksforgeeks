class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int N = arr.size();
        int l = 0, e = N - 1;
        
        int mid = l + ( e - l )/2;
        
        while( l <= e )
        {
            if(arr[mid] == k )
            {
                return mid;
            }
            else if( arr[mid] > k )
            {
                e = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            
            mid = l + ( e - l )/2;
        }
        
        return l;
    }
};