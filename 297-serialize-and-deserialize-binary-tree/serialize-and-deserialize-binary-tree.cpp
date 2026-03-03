class Codec {
public:

    string serialize(TreeNode* root) {
        if(root == nullptr) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) {
                s += "null,";
            }
            else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!getline(ss, str, ',')) break;

            if(str != "null") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            if(!getline(ss, str, ',')) break;

            if(str != "null") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};