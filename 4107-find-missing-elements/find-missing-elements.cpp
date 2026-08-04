class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int missing = nums[i] + 1; missing < nums[i + 1]; missing++) {
                result.push_back(missing);
            }
        }
        return result;

    }
};