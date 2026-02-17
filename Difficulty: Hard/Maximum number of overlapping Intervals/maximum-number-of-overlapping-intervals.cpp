class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
         int n = arr.size();

    vector<int> start(n), end(n);

    // Separate start and end times
    for (int i = 0; i < n; i++) {
        start[i] = arr[i][0];
        end[i] = arr[i][1];
    }

    // Sort both arrays
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int currOverlap = 0;
    int maxOverlap = 0;

    while (i < n && j < n) {
        // Since intervals are inclusive
        if (start[i] <= end[j]) {
            currOverlap++;
            maxOverlap = max(maxOverlap, currOverlap);
            i++;
        } else {
            currOverlap--;
            j++;
        }
    }

    return maxOverlap;
    }
};
