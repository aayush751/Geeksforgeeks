class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        int idx = 0;
        
        int twice = 0;
        
        for(int i = 0; i < n; i++ )
        {
            idx = abs( arr[i] );
            
            if( arr[ idx - 1 ] > 0 )
            {
                arr[ idx - 1 ] = arr[ idx - 1 ] * - 1;
            }
            else
            {
                twice = abs( arr[i] );
            }
        }
        
        int missing = 0;
        
        for(int i = 0; i < n; i++ )
        {
            if( arr[i] > 0 )
            {
                missing = i + 1;
            }
        }
        
        return { twice, missing };
    }
};
