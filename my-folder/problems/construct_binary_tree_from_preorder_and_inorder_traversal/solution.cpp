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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int p_s, int p_e, int i_s, int i_e)
    {
        if(i_s > i_e || p_s > p_e)
            return NULL;
        int root = preorder[p_s];
        int index = -1;
        for(int i = 0; i <= inorder.size(); i++)
        {
            if(root == inorder[i])
            {
                index = i;
                break;
            }
        }
        int l_i_s = i_s;
        int l_i_e = index-1;
        int l_p_s = p_s + 1;
        int l_p_e = l_i_e - l_i_s + l_p_s;
        int r_i_s = index + 1;
        int r_i_e = i_e;        
        int r_p_s = l_p_e + 1;
        int r_p_e = p_e;
        TreeNode* newNode = new TreeNode(root);
        newNode -> left = helper(preorder, inorder, l_p_s, l_p_e, l_i_s, l_i_e);
        newNode -> right = helper(preorder, inorder, r_p_s, r_p_e, r_i_s, r_i_e);
        return newNode;
        
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size() - 1);
    }
};