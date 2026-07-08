class Solution {
public:
    static void solve(int  idx,const string& digits,string& curr,vector<string>& ans,vector<string>& mpp){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        for(char ch:mpp[digits[idx]-'0']){
            curr.push_back(ch);
            solve(idx+1,digits,curr,ans,mpp);
            curr.pop_back();
        }
    }
    static vector<string> letterCombinations(const string& digits) {
        //write your code here 
        vector<string> ans;
        if(digits.empty()) return ans;
        vector<string> mpp(10);
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";
        string curr;
        solve(0,digits,curr,ans,mpp);
        return ans;
    }
};