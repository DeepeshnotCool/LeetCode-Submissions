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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxi = INT_MIN;
        while(!q.empty())
        {
            int size = q.size();
            //int x = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++)
            {
                auto front = q.front().first;
                int value = q.front().second;
                q.pop();
                if(i == 0)
                    first = value;
                if(i == size-1)
                    last = value;
                if(front -> left != NULL)
                {
                    q.push({front -> left,(long long)value*2 + 1});
                }
                if(front -> right != NULL)
                {
                    q.push({front -> right,(long long)value*2 + 2});
                }
            }
            maxi = max(maxi, last-first+1);
        }
        return maxi;
    }
};