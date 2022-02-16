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
    bool helper(TreeNode* root, long long int min, long long int max)
    {
        //cout<<min<<" "<<max<<" "<<INT_MIN<<" "<<INT_MAX;
        if(root == NULL)
            return true;
        if(root -> val <= min || root -> val >= max)
        {
            return false;
        }
        return helper(root -> left, min, root -> val) && helper(root -> right, root -> val, max);
    }
    bool isValidBST(TreeNode* root) {
        long long min = INT_MIN;
        long long max = INT_MAX;
        min--;
        max++;
        return helper(root,min,max);
    }
};