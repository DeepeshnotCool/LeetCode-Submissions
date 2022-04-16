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
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        inorder(root-> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }

    void helper(TreeNode* root, map<int, int> &m){
        if(root == NULL)
            return;
        root -> val = m[root -> val];
        helper(root -> left, m);
        helper(root -> right, m);
    }

    TreeNode* convertBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int sum = accumulate(v.begin(), v.end(), 0);
        vector<int> precompute(v.size(),0);
        partial_sum(v.begin(), v.end(), precompute.begin());
        map<int, int> m;
        for(int i = 0; i < v.size(); i++){
            m[v[i]] = sum-precompute[i]+v[i];
        }
        helper(root, m);
        return root;
    }
};