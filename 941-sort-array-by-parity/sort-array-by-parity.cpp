class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = nums.size();

        int i = 0;
        int j = 0;

        while (i < n && j < n){
           while (i<n && nums[i] % 2 != 0 ) i++;
            if (i < n && j < n) swap(nums[i], nums[j]);

            i++; 
            j++;
        }

        return nums;
    }
};