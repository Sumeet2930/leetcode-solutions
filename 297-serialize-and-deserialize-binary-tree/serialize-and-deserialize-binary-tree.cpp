/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeHelper(TreeNode* root, string &result) {
        if(root == nullptr) {
            result += "N,";
            return;
        }

        result += to_string(root->val) + ",";

        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serializeHelper(root,result);
        return result;
    }


    TreeNode* deserializeHelper(queue<string> &q) {
        string val = q.front();
        q.pop();

        if (val == "N") {
            return nullptr;
        }

        // Create node
        TreeNode* node = new TreeNode(stoi(val));

        // Rebuild left subtree
        node->left = deserializeHelper(q);

        // Rebuild right subtree
        node->right = deserializeHelper(q);

        return node;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";

        // Split string by comma
        for (char c : data) {
            if (c == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        return deserializeHelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));