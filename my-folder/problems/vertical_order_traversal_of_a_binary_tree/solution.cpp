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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL)
        {
            vector<vector<int>> v;
            return v;
        }
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> m;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int vertical = front.second.first;
            int level = front.second.second;
            m[vertical][level].insert(node->val);
            if(node -> left != NULL)
            {
                q.push({node->left,{vertical - 1, level + 1}});
            }
            if(node -> right != NULL)
            {
                q.push({node -> right,{vertical + 1, level + 1}});
            }
        }
        vector<vector<int>> v;
        for(auto it: m)
        {
            vector<int> temp;
            for(auto it1: it.second)
            {
                for(auto it2 = it1.second.begin(); it2 != it1.second.end(); it2++)
                {
                    temp.push_back(*it2);
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};