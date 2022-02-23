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
        string s = "";
        if(root == NULL)
            return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front == NULL)
            {
                s += "#,";
                continue;
            }
            s += to_string(front -> val) + ",";
            if(front -> left != NULL)
            {
                q.push(front -> left);
            }
            else
                q.push(NULL);
            if(front -> right != NULL)
            {
                q.push(front -> right);
            }
            else
                q.push(NULL);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        stringstream ss(data);
        string s;
        getline(ss,s,',');
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            getline(ss,s,',');
            if(s == "#")
            {
                front -> left == NULL;
            }
            else
            {
                TreeNode* node = new TreeNode(stoi(s));
                front -> left = node;
                q.push(front -> left);
            }
            getline(ss,s,',');
            if(s == "#")
            {
                front -> right = NULL;
            }
            else
            {
                TreeNode* node = new TreeNode(stoi(s));
                front -> right = node;
                q.push(front -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;