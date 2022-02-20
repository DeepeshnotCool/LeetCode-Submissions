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
        int maxi = INT_MIN;
        for(int i = left; i <= right; i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                index = i;
            }
        }
        //cout<<index<<" ";
        TreeNode* root = new TreeNode(nums[index]);
        //cout<<root -> val<<endl;
        root -> left = helper(nums, left, index-1, index);
        root -> right = helper(nums, index + 1, right, index);
        return root;        
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1, -1);
    }
};