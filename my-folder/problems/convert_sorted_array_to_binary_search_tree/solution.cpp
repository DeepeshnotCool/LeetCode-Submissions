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
    TreeNode* helper(vector<int>& nums, int left, int right, int index)
    {
        if(left > right)
            return NULL;
        index = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[index]);
        root -> left = helper(nums, left, index-1, index);
        root -> right = helper(nums, index + 1, right, index);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1, -1);
    }
};