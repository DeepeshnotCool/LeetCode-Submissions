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
    void helper(TreeNode* root, int &sum, int n){
        if(root == NULL)
            return;
        n = n*10 + root -> val;
        helper(root -> left, sum, n);
        helper(root -> right, sum, n);
        if(root -> left == NULL && root -> right == NULL){
            sum += n;
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int n = 0;
        helper(root, sum, n);
        return sum;
    }
};