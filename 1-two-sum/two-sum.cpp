class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i< nums.size(); i++){
            int compliment = target - nums[i];

            if (numMap.find(compliment) != numMap.end()){
                return  {numMap[compliment] , i};
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};