
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        for(int i = 0; i < arr.size(); i++ )
        {
            if( arr[i] <= 0 )
            {
                arr[i] = n + 1;
            }
        }
        
        for(int i = 0; i < n; i++ )
        {
            if( abs(arr[i]) <= n and arr[ abs(arr[i]) - 1 ] > 0 )
            {
                arr[ abs(arr[i]) - 1 ] = arr[ abs(arr[i]) - 1 ] * - 1;
            }
        }
        
        for(int i = 0; i < n; i++ )
        {
            if( arr[i] > 0 )
            {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
