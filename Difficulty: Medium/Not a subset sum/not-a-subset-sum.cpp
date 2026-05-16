class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end());
        
        // 'res' tracks the smallest positive integer we cannot form yet
        long long res = 1; 

        for (int i = 0; i < arr.size(); i++) {
            // If the current element is strictly greater than res, 
            // we can't form res. We break out of the loop.
            if (arr[i] > res) {
                break;
            }
            // Otherwise, add the current element to res
            res += arr[i];
        }

        return res;
    }
};