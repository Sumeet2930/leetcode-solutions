class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        long long add = 0;
        str.erase(std::remove(str.begin(), str.end(), '0'), str.end());
        int result = str.empty() ? 0 : std::stoll(str);
        
        for (char c : str){
            add += c - '0';
        }

        return result * add;
    }
};