#include <vector>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::vector<int> count(1001, 0);
        for (int num : arr1) {
            count[num]++;
        }
        
        std::vector<int> result;
        
        
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        

        for (int num = 0; num <= 1000; num++) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        return result;
    }
};