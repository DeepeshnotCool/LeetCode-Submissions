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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                v.push_back(front -> val);
                if(front -> left != NULL)
                    q.push(front -> left);
                if(front -> right != NULL)
                    q.push(front -> right);
            }
            if(flag)
            {
                ans.push_back(v);
                flag = false;
            }
            else
            {
                reverse(v.begin(),v.end());
                ans.push_back(v);
                flag = true;
            }
        }
        return ans;
        
    }
};