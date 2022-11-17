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

    int helper(TreeNode* root, int& targetSum, int& ans, long long int& sum){
        if(root == NULL)
            return 0;
        int temp = 0;
        sum += root -> val;
        if(sum == targetSum)
            temp++;
        temp += helper(root -> left, targetSum, ans, sum);
        temp += helper(root -> right, targetSum, ans, sum);
        sum -= root -> val;
        return temp;
    }

    void preorder(TreeNode* root, int& targetSum, int& ans, long long int& sum){
        if(root == NULL)
            return;
        ans += helper(root, targetSum, ans, sum);
        preorder(root -> left, targetSum, ans, sum);
        preorder(root -> right, targetSum, ans, sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        long long sum = 0;
        int ans = 0;
        preorder(root, targetSum, ans, sum);
        return ans;
    }
};




