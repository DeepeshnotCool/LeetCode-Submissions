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
    bool isleaf(TreeNode* root)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            return true;
        }
        return false;
    }
    void helper(TreeNode* root, int &sum)
    {
        if(root == NULL)
            return;
        if(root -> left != NULL)
        {
            if(isleaf(root -> left))
            { 
                sum += root -> left -> val;
            }
        }
        helper(root -> left, sum);
        helper(root -> right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return sum;
    }   
};









