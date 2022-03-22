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
     
    int helper(TreeNode* root, map<TreeNode*, int> &m){
        if(root == NULL)
            return 0;
        if(m.count(root) != 0){
            return m[root];
        }
        int ll, lr, rl, rr;
        ll = lr = rl = rr = 0;
        
        if(root -> left != NULL){
            ll = helper(root -> left -> left, m);
            lr = helper(root -> left -> right, m);
        }
        if(root -> right != NULL){
            rl = helper(root -> right -> left, m);
            rr = helper(root -> right -> right, m);
        }
        
        int a = root -> val + ll + lr + rl + rr;
        int b = helper(root -> left, m) + helper(root -> right, m);
        
        return m[root] = max(a, b);
    }
    
    
    int rob(TreeNode* root) {
        map<TreeNode* , int> m;
        return helper(root, m);
    }
};