class Solution {
public:
    int reverseBits(int n) {
        string binary = bitset<32>(n).to_string();

        reverse(binary.begin(), binary.end());

        return bitset<32>(binary).to_ulong();
    }
};