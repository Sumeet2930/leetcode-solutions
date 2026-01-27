class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, mid, right;

        for (int x : nums) {
            if (x < pivot)
                left.push_back(x);
            else if (x == pivot)
                mid.push_back(x);
            else
                right.push_back(x);
        }

        vector<int> result;
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), mid.begin(), mid.end());
        result.insert(result.end(), right.begin(), right.end());

        return result;
    }
};
