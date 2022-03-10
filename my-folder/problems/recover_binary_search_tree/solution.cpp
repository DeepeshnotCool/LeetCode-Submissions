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
    
    void inorder(TreeNode* root, vector<TreeNode*> &v)
    {
        if(root == NULL)
            return;
        inorder(root -> left, v);
        v.push_back(root);
        inorder(root -> right, v);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i]-> val < v[i-1]->val)
            {
                first = v[i-1];
                int mini = INT_MAX;
                for(int j = i; j < v.size(); j++)
                {
                    if(v[j] -> val < mini)
                    {
                        second = v[j];
                        mini = v[j] -> val;
                    }
                }
                break;
            }
        }
        if(first != NULL && second != NULL)
        {
            int temp = first -> val;
            first -> val = second -> val;
            second -> val = temp;
        }
    }
};