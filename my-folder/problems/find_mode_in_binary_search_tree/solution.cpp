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
    void helper(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;
        v.push_back(root -> val);
        helper(root -> left, v);
        helper(root -> right, v);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        map<int, int> m;
        for(int i = 0; i < v.size(); i++)
        {
            m[v[i]]++;
        }
        int maxi = INT_MIN;
        for(auto it : m)
        {
           if(it.second > maxi)
           {
               maxi = it.second;
            }
        }
        vector<int> ans;
        for(auto it : m)
        {
            if(it.second == maxi)
                ans.push_back(it.first);
        }
        return ans;
    }
};