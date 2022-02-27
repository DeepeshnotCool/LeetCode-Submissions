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
    void dfs(TreeNode* root, set<int> &s)
    {
        if(root == NULL)
            return;
        s.insert(root -> val);
        dfs(root -> left, s);
        dfs(root -> right, s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(root,s);
        vector<int> v;
        for(auto x : s)
            v.push_back(x);
        if(v.size() >= 2)
            return v[1];
        else
            v[0];
        return -1;
    }
};