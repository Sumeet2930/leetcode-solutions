class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int cur = nums[0];
        int max_sum = nums[0];

        for (int i=1; i<nums.size(); i++){
            cur = max(nums[i], cur + nums[i]);
            max_sum = max(cur, max_sum);
        }
        return max_sum;
    }
};