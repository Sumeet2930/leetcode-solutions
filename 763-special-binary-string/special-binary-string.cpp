class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> substrings;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // When count becomes 0, we found a special substring
            if (count == 0) {
                // Recursively solve inner substring
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                substrings.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort in descending order
        sort(substrings.begin(), substrings.end(), greater<string>());

        string result;
        for (string &str : substrings)
            result += str;

        return result;
    }
};