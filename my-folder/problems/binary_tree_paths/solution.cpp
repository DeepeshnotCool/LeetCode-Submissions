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
    
    void helper(TreeNode* root, string s, vector<string> &v)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            s += to_string(root -> val);
            v.push_back(s);
            return;
        }
        s += to_string(root -> val) + "->";
        if(root -> left != NULL)
            helper(root -> left, s, v);
        if(root -> right != NULL)
            helper(root -> right, s, v);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s = "";
        helper(root, s, v);
        return v;
    }
};