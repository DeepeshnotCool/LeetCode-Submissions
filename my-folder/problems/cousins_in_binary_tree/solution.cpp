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
    
    
    void helper(map<int, pair<int, int>> &m, TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                if(front -> left != NULL)
                {
                    q.push(front -> left);
                    m[front -> left -> val] = {front -> val, level+1};
                }
                if(front -> right != NULL)
                {
                    q.push(front -> right);
                    m[front -> right -> val] = {front -> val, level+1};
                }
            }
            level++;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        map<int, pair<int, int>> m;
        helper(m, root);
        for(auto it : m)
        {
            cout<<it.first<<"-"<<it.second.first<<","<<it.second.second<<endl;
        }
        if(m[x].first == m[y].first)
        {
            return false;
        }
        else
        {
            if(m[x].second == m[y].second)
                return true;
        }
        return false;
    }
};