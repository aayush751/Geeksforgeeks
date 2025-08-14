class Solution {
  public:
    int countRevPairs(vector<int> &nums ) {
        // Code here
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    int merge(std::vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;

        // Counting the reverse pairs
        for (int i = low; i <= mid; ++i) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merging the two sorted halves
        std::vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; ++i) {
            nums[i] = temp[i - low];
        }
        
        return count;
    }

    int mergeSort(std::vector<int>& nums, int low, int high) {
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;
        int count = 0;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);
        
        return count;
    }
};