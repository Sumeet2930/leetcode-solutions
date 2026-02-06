class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        int count1 = 0;
        int count2 = 0;
        
        // Count elements in nums1 present in nums2
        for(int num : nums1) {
            if(set2.count(num)) {
                count1++;
            }
        }
        
        // Count elements in nums2 present in nums1
        for(int num : nums2) {
            if(set1.count(num)) {
                count2++;
            }
        }
        
        return {count1, count2};
    }
};
