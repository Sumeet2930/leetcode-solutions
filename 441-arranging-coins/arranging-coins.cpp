class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0;
        
        for (int i = 1; i <= n; i++) {
            if (n >= i) {
                n -= i;   // use coins for this row
                row++;    // completed one row
            } else {
                break;
            }
        }
        return row;
    }
};
