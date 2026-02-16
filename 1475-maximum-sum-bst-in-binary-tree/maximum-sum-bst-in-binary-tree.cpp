/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = 0;

    vector<int> dfs(TreeNode* root) {
        if (!root) 
            return {1, 0, INT_MAX, INT_MIN};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // check BST condition
        if (left[0] && right[0] && 
            root->val > left[3] && 
            root->val < right[2]) {
            
            int sum = left[1] + right[1] + root->val;
            maxSum = max(maxSum, sum);

            int mn = min(root->val, left[2]);
            int mx = max(root->val, right[3]);

            return {1, sum, mn, mx};
        }

        return {0, 0, 0, 0};  // not BST
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
