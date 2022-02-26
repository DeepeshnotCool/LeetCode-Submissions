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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* node = root;
        while(1)
        {
            if(node -> val >= val)
            {
                if(node -> left == NULL)
                {
                    TreeNode* newNode = new TreeNode(val);
                    node -> left = newNode;
                    break;
                }
                node = node -> left;
            }
            else
            {
                if(node -> right == NULL)
                {
                    TreeNode* newNode = new TreeNode(val);
                    node -> right = newNode;
                    break;
                }
                node = node -> right;
            }
        }
        return root;
    }
};