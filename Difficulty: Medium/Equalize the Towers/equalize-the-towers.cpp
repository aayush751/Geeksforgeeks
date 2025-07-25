class Solution {
  public:
     bool check(vector<int>& heights, vector<int>& cost, int mid) {
        long long costMid   = 0;
        long long costMidP1 = 0;

        for (int i = 0; i < heights.size(); i++) {
            costMid   += (long long)abs(heights[i] - mid) * cost[i];
            costMidP1 += (long long)abs(heights[i] - (mid + 1)) * cost[i];
        }

        return costMid < costMidP1;  // true if mid gives smaller cost than mid+1 (move left)
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        // Define search boundaries for binary search
        int low  = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());

        int targetH = 0;  // best height found

        while (low <= high) {
            int mid = (low + high) / 2;

            // Move toward the side with lower cost
            if (check(heights, cost, mid)) {
                targetH = mid;
                high    = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Calculate final cost using chosen target height
        long long result = 0;
        for (int i = 0; i < heights.size(); i++) {
            result += (long long)abs(heights[i] - targetH) * cost[i];
        }

        return (int)result;
    }
};
