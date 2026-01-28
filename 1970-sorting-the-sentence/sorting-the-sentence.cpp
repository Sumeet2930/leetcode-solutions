class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10); 
        string temp = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                int pos = temp.back() - '0';
                temp.pop_back();
                words[pos] = temp;
                temp = "";
            } else {
                temp += s[i];
            }
        }

        
        int pos = temp.back() - '0';
        temp.pop_back();
        words[pos] = temp;

        string result = "";
        for (int i = 1; i < words.size(); i++) {
            if (words[i] != "") {
                result += words[i] + " ";
            }
        }

        result.pop_back(); 
        return result;
    }
};
