class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
    
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = nullptr;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start) {
                startNode = curr;
            }

            if (curr->left != nullptr) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right != nullptr) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }


        queue<TreeNode*> infectionQueue;
        unordered_set<TreeNode*> visited;
        
        infectionQueue.push(startNode);
        visited.insert(startNode);
        
        int minutes = -1; 

        while (!infectionQueue.empty()) {
            int size = infectionQueue.size();
            minutes++; 
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = infectionQueue.front();
                infectionQueue.pop();

                if (curr->left && visited.find(curr->left) == visited.end()) {
                    visited.insert(curr->left);
                    infectionQueue.push(curr->left);
                }
                
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    visited.insert(curr->right);
                    infectionQueue.push(curr->right);
                }
                
                if (parentMap.count(curr) && visited.find(parentMap[curr]) == visited.end()) {
                    visited.insert(parentMap[curr]);
                    infectionQueue.push(parentMap[curr]);
                }
            }
        }

        return minutes;
    }
};