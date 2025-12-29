class Solution {
  public:
    int kthElement(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        if (k > (n1 + n2) || k <= 0 ) 
        {
            return -1;
        }
    
        int low = max(0, k - n2);
        int high = min(n1, k);
    
        while (low < high) 
        {
            int mid1 = (low + high) / 2;
            int mid2 = k - mid1;
    
            if (mid2 > 0 && mid1 < n1 && arr2[mid2 - 1] > arr1[mid1]) 
            {
                low = mid1 + 1;
            } 
            else if (mid1 > 0 && mid2 < n2 && arr1[mid1 - 1] > arr2[mid2]) 
            {
                high = mid1 - 1;
            } 
            else 
            {
                low = mid1;
                break;
            }
        }
    
        int mid1 = low;
        int mid2 = k - mid1;
    
        int a = mid1 > 0 ? arr1[mid1 - 1] : INT_MIN;
        int b = mid2 > 0 ? arr2[mid2 - 1] : INT_MIN;
    
        return max(a, b);
    }
};