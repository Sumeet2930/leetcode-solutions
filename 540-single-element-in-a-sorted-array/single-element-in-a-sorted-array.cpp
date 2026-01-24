class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, high = n - 1;

        while (left < high){
            int mid = left + (high - left) / 2;

            if (mid % 2 == 1){
                mid --;
            }

            if (nums[mid] == nums[mid + 1]){
                left = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[left] ;
    }
};