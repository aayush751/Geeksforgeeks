class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> odd, even;

    // Separate odd and even numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0)
            odd.push_back(arr[i]);
        else
            even.push_back(arr[i]);
    }

    // Sort odd in descending order
    sort(odd.begin(), odd.end(), greater<int>());

    // Sort even in ascending order
    sort(even.begin(), even.end());

    // Put back into original array
    int idx = 0;
    for (int x : odd)
        arr[idx++] = x;
    for (int x : even)
        arr[idx++] = x;
    }
};