class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int count = 0;
        unordered_map< int, int > sumCount;
        
        sumCount[0] = 1;
        
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            sum += arr[i];
            
            if( sumCount.find( sum - k ) != sumCount.end() )
            {
                count += sumCount[sum - k];
            }
            sumCount[sum]++;
        }
        
        return count;
    }
};