class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the last element
            // then minimum is in the right part
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Otherwise, minimum is in left part (including mid)
            else {
                high = mid;
            }
        }

        // low == high -> index of minimum element
        return nums[low];
    }
};
