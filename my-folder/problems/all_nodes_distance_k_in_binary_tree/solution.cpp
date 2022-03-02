/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void point_the_pointer(map<TreeNode*, TreeNode*> &m, TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front -> left != NULL)
            {
                q.push(front -> left);
                m[front -> left] = front;
            }
            if(front -> right != NULL)
            {
                q.push(front -> right);
                m[front -> right] = front;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        if(root == NULL)
            return v;
        map<TreeNode*, TreeNode*> m;
        point_the_pointer(m, root);
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, bool> visited;
        visited[target] = true;
        int count = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(count == k)
                break;
            count++;
            for(int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                if(front -> left != NULL && !visited[front -> left])
                {
                    q.push(front -> left);
                    visited[front -> left] = true;
                }
                if(front -> right != NULL && !visited[front -> right])
                {
                    q.push(front -> right);
                    visited[front -> right] = true;
                }
                if(m[front] != NULL && !visited[m[front]])
                {
                    q.push(m[front]);
                    visited[m[front]] = true;
                }
            }
        }
        while(!q.empty())
        {
            v.push_back(q.front() -> val);
            q.pop();
        }
        return v;
    }
};