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
    vector<vector<int>> ans;
    void helper(TreeNode* root, int targetSum, int &sum, vector<int> &v)
    {
        if(root == NULL)
            return;
        v.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL)
        {
            sum += root -> val; 
            if(sum == targetSum)
            {
                ans.push_back(v);
            }
        }
        else
        {
            sum += root -> val;
        }
        helper(root -> left, targetSum, sum, v);
        helper(root -> right, targetSum, sum, v);  
        sum -= root -> val;
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int sum = 0;
        helper(root, targetSum, sum, v);
        return ans;
    }
};