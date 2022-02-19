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
    
    void helper(TreeNode* root, int level, vector<int>& v)
    {
        if(root == NULL)
            return ;
        if(v.size() == level)
            v.push_back(root -> val);
        helper(root -> right, level + 1, v);
        helper(root -> left, level + 1, v);
    }
    
    vector<int> rightSideView(TreeNode* root) {
     /*
        vector<int> v;
        if(root == NULL)
            return v;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,TreeNode*,greater<int>>> m;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int level = front.second.first;
            int vertical = front.second.second;
            TreeNode* node = front.first;
            m[level][vertical] = node;
            if(node -> left != NULL)
            {
                q.push({node -> left,{level + 1, vertical -1}});
            }
            if(node -> right != NULL)
            {
                q.push({node -> right,{level + 1, vertical + 1}});
            }   
        }
        
        for(auto it: m)
        {
            for(auto it1 : it.second)
            {
                v.push_back(it1.second -> val);
                break;
            }
        }
        
        return v;
        
        */
        vector<int> v;
        helper(root,0,v);
        return v;
        
    }
};