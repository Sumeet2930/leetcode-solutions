class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int n : nums) mp[n]++;

        priority_queue<pair<int,int>> pq;
        for(auto &[num,freq] : mp) {
            pq.push({freq, num});
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};