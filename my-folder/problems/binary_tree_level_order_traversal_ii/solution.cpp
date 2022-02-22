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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                temp.push_back(front -> val);
                if(front -> left != NULL)
                    q.push(front -> left);
                if(front -> right != NULL)
                    q.push(front -> right);
            }
            v.push_back(temp);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};