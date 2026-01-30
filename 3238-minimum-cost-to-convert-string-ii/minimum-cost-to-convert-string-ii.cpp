class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        const long long INF = 1e18;
        int n = original.size();

        // Map strings to IDs
        unordered_map<string, int> id;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (!id.count(original[i])) id[original[i]] = idx++;
            if (!id.count(changed[i])) id[changed[i]] = idx++;
        }

        int m = idx;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++) dist[i][i] = 0;

        for (int i = 0; i < n; i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // Group strings by length
        unordered_map<int, vector<string>> byLen;
        for (auto& s : id) {
            byLen[s.first.size()].push_back(s.first);
        }

        int L = source.size();
        vector<long long> dp(L + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < L; i++) {
            if (dp[i] == INF) continue;

            // Same character → cost 0
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Try only valid lengths
            for (auto& [len, strs] : byLen) {
                if (i + len > L) continue;

                string s1 = source.substr(i, len);
                string s2 = target.substr(i, len);

                if (!id.count(s1) || !id.count(s2)) continue;

                long long c = dist[id[s1]][id[s2]];
                if (c < INF) {
                    dp[i + len] = min(dp[i + len], dp[i] + c);
                }
            }
        }

        return dp[L] == INF ? -1 : dp[L];
    }
};
