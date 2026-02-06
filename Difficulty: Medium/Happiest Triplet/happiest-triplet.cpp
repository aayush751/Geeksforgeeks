class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
           int n = a.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int i = 0, j = 0, k = 0;
    int bestDiff = INT_MAX;
    int bestSum = INT_MAX;
    vector<int> best(3);

    while (i < n && j < n && k < n) {
        int x = a[i], y = b[j], z = c[k];
        int mx = max({x, y, z});
        int mn = min({x, y, z});

        int diff = mx - mn;
        int sum = x + y + z;

        if (diff < bestDiff || (diff == bestDiff && sum < bestSum)) {
            bestDiff = diff;
            bestSum = sum;
            best = {x, y, z};
        }

        // Move pointer having minimum value
        if (mn == x) i++;
        else if (mn == y) j++;
        else k++;
    }

    // Return in decreasing order
    sort(best.begin(), best.end(), greater<int>());
    return best;
    }
};