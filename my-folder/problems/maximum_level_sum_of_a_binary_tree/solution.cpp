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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
        int level = 0;
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            int sum = 0;
            level++;
            for(int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                sum += front -> val;
                if(front -> left != NULL)
                {
                    q.push(front -> left);
                }
                if(front -> right != NULL)
                {
                    q.push(front -> right);
                }
            }
            if(sum > maxi)
            {
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};





