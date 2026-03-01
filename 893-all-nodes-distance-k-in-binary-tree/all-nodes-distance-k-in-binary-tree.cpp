class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        
        int currLevel = 0;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            if(currLevel == k)
                break;
            
            currLevel++;
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                if(parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        
        vector<int> result;
        
        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};