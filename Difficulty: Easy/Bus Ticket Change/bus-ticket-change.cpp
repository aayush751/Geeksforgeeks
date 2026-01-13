class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int five = 0, ten = 0;

        for (int note : arr) {
            if (note == 5) {
                five++;
            }
            else if (note == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else { // note == 20
                // Prefer giving 10 + 5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // Otherwise give three 5s
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;

    }
};