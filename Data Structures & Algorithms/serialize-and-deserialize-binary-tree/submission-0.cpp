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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string bst_str = "";
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            if(root == nullptr){
                bst_str+="N,";
                return;
            }
            bst_str += to_string(root->val)+",";
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return bst_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            vals.push_back(item);
        }
        int i = 0;
        function<TreeNode*()> dfs = [&]() -> TreeNode* {
            if(vals[i] == "N") {
                i++;
                return nullptr;
            }
            TreeNode* node = new TreeNode(stoi(vals[i]));
            i++;
            node->left = dfs();
            node->right = dfs();
            return node;
        };
        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));