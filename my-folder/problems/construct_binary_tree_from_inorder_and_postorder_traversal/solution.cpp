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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int i_s, int i_e, int p_s, int p_e)
    {
        if(i_s > i_e || p_s > p_e)
            return NULL;
        int root = postorder[p_e];
        int index = -1;
        for(int i = i_s; i <= inorder.size(); i++)
        {
            if(root == inorder[i])
            {
                index = i;
                break;
            }
        }
        int l_i_s = i_s;
        int l_i_e = index - 1;
        int l_p_s = p_s;
        int l_p_e = l_i_e - l_i_s + l_p_s;
        int r_i_s = index + 1;
        int r_i_e = i_e;
        int r_p_s = l_p_e + 1;
        int r_p_e = r_i_e - r_i_s + r_p_s;
        TreeNode* newNode = new TreeNode(root);
        newNode -> left = helper(inorder, postorder, l_i_s, l_i_e, l_p_s, l_p_e);
        newNode -> right = helper(inorder, postorder, r_i_s, r_i_e, r_p_s, r_p_e);
        return newNode;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};