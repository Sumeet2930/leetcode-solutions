class Solution {
public:
    int minimumPushes(string word) {
        auto ans = word.size() >> 3;
        auto r = word.size() & 7;

        return ((ans << 2) + r) * (ans + 1);
    }
};