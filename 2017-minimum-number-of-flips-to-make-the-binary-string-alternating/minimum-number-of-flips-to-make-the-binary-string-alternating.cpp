class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        int alt1 = 0, alt2 = 0;
        int ans = INT_MAX;

        for(int i = 0; i < ss.size(); i++) {

            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if(ss[i] != expected1) alt1++;
            if(ss[i] != expected2) alt2++;

            if(i >= n) {
                char prev = ss[i - n];

                char prevExp1 = ((i - n) % 2 == 0) ? '0' : '1';
                char prevExp2 = ((i - n) % 2 == 0) ? '1' : '0';

                if(prev != prevExp1) alt1--;
                if(prev != prevExp2) alt2--;
            }

            if(i >= n - 1) {
                ans = min(ans, min(alt1, alt2));
            }
        }

        return ans;
    }
};