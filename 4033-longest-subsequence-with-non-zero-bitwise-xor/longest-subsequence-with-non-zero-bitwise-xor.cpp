class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto total = 0, nonzero =0;

        for (auto &n : nums){
            nonzero |= n > 0;
            total ^= n;
        }

        return nonzero * (nums.size() - !total);
    }
};