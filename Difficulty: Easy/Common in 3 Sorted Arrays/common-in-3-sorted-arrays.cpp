class Solution {
  public:
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        // code here
        vector<int> result;
        int i = 0, j = 0, k = 0;
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();

    while (i < n1 && j < n2 && k < n3) {
        // If all three elements are equal
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            // Check if result is empty or the last inserted element is different 
            // to avoid adding duplicates
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            // Move all pointers forward
            i++;
            j++;
            k++;
        }
        // If arr1[i] is smaller than arr2[j], it can't be common. Move i forward.
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        // If arr2[j] is smaller than arr3[k], it can't be common. Move j forward.
        else if (arr2[j] < arr3[k]) {
            j++;
        }
        // If arr1[i] >= arr2[j] and arr2[j] >= arr3[k], then arr3[k] is the smallest.
        else {
            k++;
        }
    }

    return result;
    }
};