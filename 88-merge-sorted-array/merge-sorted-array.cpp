class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> arr1, arr2;
        vector<int> result(m + n);

        for (int i = 0; i < m; i++) {
            arr1.push_back(nums1[i]);
        }

        for (int j = 0; j < n; j++) {
            arr2.push_back(nums2[j]);
        }

        std::merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), result.begin());

        nums1 = result;   
    }
};
