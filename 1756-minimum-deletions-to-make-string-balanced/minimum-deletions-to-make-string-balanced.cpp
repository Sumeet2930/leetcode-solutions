class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;      // count of 'b' seen so far
        int deletions = 0;   // minimum deletions needed
        
        for(char c : s) {
            if(c == 'b') {
                bCount++;
            } else { // c == 'a'
                // Either delete this 'a'
                // OR delete all previous 'b'
                deletions = min(deletions + 1, bCount);
            }
        }
        
        return deletions;
    }
};
