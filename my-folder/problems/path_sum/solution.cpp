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
    void helper(TreeNode* root, int targetSum, bool &flag, int &sum)
    {
        if(root == NULL)
            return;
        if(root -> left == NULL && root -> right == NULL)
        {
            sum += root -> val; 
            if(sum == targetSum)
            {
                flag = true;
                return;
            }
        }
        else
        {
            sum += root -> val;
        }
        helper(root -> left, targetSum, flag, sum);
        helper(root -> right, targetSum, flag, sum);  
        sum -= root -> val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        bool flag = false;
        int sum = 0;
        helper(root, targetSum, flag, sum);
        return flag;
    }
};




