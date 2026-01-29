class Solution {
public:
    int hammingWeight(int n) {
        string binary = bitset<32>(n).to_string();

        int count = 0;
        for (int i = 0; i < 32; i++){
            if (binary[i] == '1') count++ ;
        }

        return count ;
    }
};