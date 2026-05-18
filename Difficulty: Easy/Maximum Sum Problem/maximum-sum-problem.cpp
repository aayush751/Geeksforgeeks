class Solution {
  public:
    int maxSum(int n) {
        // code here.
        if( n == 0 or n == 1 )
            {
                return n;
            }
            
            return max( (maxSum( n / 2) + maxSum( n / 3 ) + maxSum( n / 4 )) , n );
    }
};