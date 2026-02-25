class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If found, find the just larger element from the right
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the elements from i+1 till end
        reverse(nums.begin() + i + 1, nums.end());
    }
};
