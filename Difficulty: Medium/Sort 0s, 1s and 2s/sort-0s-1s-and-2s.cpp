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
