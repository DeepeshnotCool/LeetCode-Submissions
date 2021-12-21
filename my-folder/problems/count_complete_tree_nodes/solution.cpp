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
    int countNodes(TreeNode* root) {
        if(root == NULL)
                return 0;
        int lh = leftHeight(root -> left);
        int rh = rightHeight(root -> right);
        
        if(lh == rh) return (1<<lh) -1;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    int leftHeight(TreeNode *node)
    {  
        int h = 1;
        while(node != NULL)
        {
            h++;
            node = node -> left;
        }
        return h;
    }
    
    int rightHeight(TreeNode *node)
    {
            int h = 1;
            while(node != NULL)
            {
                h++;
                node = node -> right;
            }
            return h;
    }
};