class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter = 0;
        string result = "";

        for (auto str : s) {
            if(str == '('){
                if (counter > 0) result += str;
                counter++;
            } else {
                counter--;
                if (counter > 0) result += str;
            }
        }

        return result;
    }
};