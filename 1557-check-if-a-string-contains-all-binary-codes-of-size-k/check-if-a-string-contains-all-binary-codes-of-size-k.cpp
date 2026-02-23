class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(s.length() < k) return false;
        
        int total = 1 << k;
        unordered_set<string> st;
        
        for(int i = 0; i <= s.length() - k; i++){
            st.insert(s.substr(i, k));
            
            if(st.size() == total)
                return true;
        }
        
        return st.size() == total;
    }
};