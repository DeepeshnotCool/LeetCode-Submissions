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
    bool levelOrder(TreeNode* root)
    {
        if(root == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i< size; i++)
            {
                auto front = q.front();
                q.pop();
                temp.push_back(front->val);
                if(front -> left != NULL)
                    q.push(front -> left);
                if(front -> right != NULL)
                    q.push(front -> right);
            }
            if(i%2 == 0)
            {
                if(temp[0]%2 == 0)
                    return false;
                for(int i = 1; i < temp.size(); i++)
                {
                    if(temp[i]%2 == 0)
                        return false;
                    if(temp[i]<=temp[i-1])
                        return false;
                }
            }
            else
            {
                if(temp[0]%2 != 0)
                    return false;
                for(int i = 1; i < temp.size(); i++)
                {
                    if(temp[i]%2 != 0)
                        return false;
                    if(temp[i]>=temp[i-1])
                        return false;
                }
            }
            i++;
        }
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) {
        return levelOrder(root);
    }
};