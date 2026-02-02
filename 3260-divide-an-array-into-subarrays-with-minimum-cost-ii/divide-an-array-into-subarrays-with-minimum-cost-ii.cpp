class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        const long long INF = 1e18;

        // First subarray always starts at index 0
        long long base = nums[0];
        long long ans = INF;

        multiset<int> low, high;
        long long sumLow = 0;

        // Helper lambdas
        auto balance = [&]() {
            while (low.size() > k - 1) {
                auto it = prev(low.end());
                sumLow -= *it;
                high.insert(*it);
                low.erase(it);
            }
            while (low.size() < k - 1 && !high.empty()) {
                auto it = high.begin();
                sumLow += *it;
                low.insert(*it);
                high.erase(it);
            }
        };

        auto add = [&](int x) {
            if (low.empty() || x <= *prev(low.end())) {
                low.insert(x);
                sumLow += x;
            } else {
                high.insert(x);
            }
            balance();
        };

        auto remove = [&](int x) {
            auto itLow = low.find(x);
            if (itLow != low.end()) {
                sumLow -= x;
                low.erase(itLow);
            } else {
                high.erase(high.find(x));
            }
            balance();
        };

        // Initial window: [1 ... dist + 1]
        for (int i = 1; i <= dist + 1 && i < n; i++) {
            add(nums[i]);
        }

        if (low.size() == k - 1) {
            ans = min(ans, base + sumLow);
        }

        // Slide the window
        for (int i = dist + 2; i < n; i++) {
            add(nums[i]);
            remove(nums[i - (dist + 1)]);

            if (low.size() == k - 1) {
                ans = min(ans, base + sumLow);
            }
        }

        return ans;
    }
};
