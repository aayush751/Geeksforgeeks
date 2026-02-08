class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
         int prefix = 1;
        int suffix = 1;
        int n = arr.size();
        
        int product = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            if( prefix == 0 )
            {
                prefix = 1;
            }
            
            if( suffix == 0 )
            {
                suffix = 1;
            }
            
            prefix = prefix * arr[i];
            suffix = suffix * arr[n - i - 1];
            
            product = max( product, max( prefix, suffix ) );
        }
        
        return product;
    }
};