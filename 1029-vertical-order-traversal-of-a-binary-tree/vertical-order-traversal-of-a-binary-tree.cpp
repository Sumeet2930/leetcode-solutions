class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            nodes[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, {row+1, col-1}});

            if(node->right)
                q.push({node->right, {row+1, col+1}});

        }
        vector<vector<int>> result;

        for(auto &p : nodes) {
            vector<int> column;

            for(auto &q : p.second) {
                column.insert(column.end(), 
                              q.second.begin(), 
                              q.second.end());
            }

            result.push_back(column);
        }
        return result;
    }
};