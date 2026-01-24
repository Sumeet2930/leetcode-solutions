class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        int n = nums.size();
        if (n == 0) return result;

        // First position (lower bound)
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (low >= n || nums[low] != target) return result;
        result[0] = low;

        // Last position (upper bound)
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        result[1] = high;
        return result;
    }
};
