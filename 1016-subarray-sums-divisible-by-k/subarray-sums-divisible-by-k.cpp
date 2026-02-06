class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // important
        
        int prefix = 0;
        int count = 0;
        
        for(int num : nums) {
            prefix += num;
            
            int rem = prefix % k;
            
            if(rem < 0)
                rem += k;   // handle negative
            
            if(mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            
            mp[rem]++;
        }
        
        return count;
    }
};
