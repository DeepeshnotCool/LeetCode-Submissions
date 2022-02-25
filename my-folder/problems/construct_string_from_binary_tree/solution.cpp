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
    void helper(TreeNode* root, string &s)
    {
        if(root == NULL)
            return;
        s += '(' + to_string(root->val);
        if(root -> left == NULL && root -> right != NULL)
            s += "()";
        else
            helper(root -> left, s);
        helper(root -> right, s);
        s += ')';
    }
    string tree2str(TreeNode* root) {
        string s = "";
        helper(root, s);
        return s.substr(1,s.size()-2);
    }
};