class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int maxKadane = INT_MIN;
        int sum = 0;
        
        for( int i = 0; i < arr.size(); i++ )
        {
            sum += arr[i];
            maxKadane = max( sum, maxKadane );
            
            if( sum < 0 )
            {
                sum = 0;
            }
        }
        
        sum = 0;
        int minKadane = INT_MAX;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            sum += arr[i];
            minKadane = min( sum, minKadane );
            
            if( sum > 0 )
            {
                sum = 0;
            }
        }
        
        int totalSum = accumulate( arr.begin(), arr.end(), 0 );
        
        int maxCCircularSum = totalSum - minKadane;
        
        if( maxKadane < 0 ) return maxKadane;
        
        return max( maxCCircularSum, maxKadane );
    }
};