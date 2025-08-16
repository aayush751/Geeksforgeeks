class Solution {
  public:
    string findLargest(vector<int> &nums ) {
        // code here
        vector<std::string> s_nums;
        for (int num : nums) {
            s_nums.push_back(std::to_string(num));
        }

        // Sort the strings using a custom comparator
        std::sort(s_nums.begin(), s_nums.end(), [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });

        // Handle the edge case where all numbers are zero
        if (s_nums[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings
        std::string result = "";
        for (const std::string& s : s_nums) {
            result += s;
        }

        return result;
    }
};