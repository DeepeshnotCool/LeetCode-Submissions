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
    map<int, int> l, r, h;
    int height(TreeNode* root){
        if(!root)
            return 0;
        int lh = height(root -> left);
        int rh = height(root -> right);

        l[root -> val] = lh;
        r[root -> val] = rh;

        return max(lh, rh) + 1;
    }

    void helper(TreeNode* root, int maxi, int depth){
        if(!root)
            return;
        h[root -> val] = maxi;
        helper(root -> left, max(maxi, depth + r[root -> val]), depth + 1);
        helper(root -> right, max(maxi, depth + l[root -> val]), depth + 1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        helper(root -> left, r[root -> val], 1);
        helper(root -> right, l[root -> val], 1);

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            ans.push_back(h[queries[i]]);
        }
        return ans;
    }
};