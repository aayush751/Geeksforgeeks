class Solution {
  public:
  
    int largestRectangleInHistogram(std::vector<int>& heights) {
        std::stack<int> s;
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            // Use a height of 0 for the imaginary bar at the end
            // to flush out all remaining bars from the stack.
            int current_height = (i == n) ? 0 : heights[i];

            while (!s.empty() && heights[s.top()] >= current_height) {
                int height_of_bar = heights[s.top()];
                s.pop();

                // Calculate the width of the rectangle.
                // If the stack is empty, the rectangle extends to the beginning.
                int width = s.empty() ? i : i - s.top() - 1;
                
                max_area = std::max(max_area, height_of_bar * width);
            }
            s.push(i);
        }
        return max_area;
    }
    
    
    int maxArea(vector<vector<int>> &matrix) {
        // code here
         if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int max_area = 0;

        for (int i = 0; i < rows; ++i) {
            // Update the heights vector for the current row
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Calculate max area for the histogram represented by the current heights
            max_area = std::max(max_area, largestRectangleInHistogram(heights));
        }

        return max_area;
    }
};