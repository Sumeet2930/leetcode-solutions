class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(vector<int> &candidates, int target, int index){
        
        //Base Case bana liya ..
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0) return; // One more Base Case if minus mein ho toh 

        for (int i=index; i<candidates.size(); i++){
            temp.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
             backtrack(candidates, target, 0);
        return ans;
    }
};