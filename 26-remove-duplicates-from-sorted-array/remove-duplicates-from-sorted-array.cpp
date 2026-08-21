class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> num(nums.begin(), nums.end());

        int index = 0;
        for (int n : num){
            nums[index] = n;
            index++;
        }
        return num.size();
    }
};