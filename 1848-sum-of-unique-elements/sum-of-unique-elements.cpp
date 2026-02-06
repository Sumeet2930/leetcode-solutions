class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int,int> freq;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        for(int i=0; i<n; i++){
            if(freq[nums[i]] == 1){
                ans += nums[i];
            }
        }

        return ans;
    }
};