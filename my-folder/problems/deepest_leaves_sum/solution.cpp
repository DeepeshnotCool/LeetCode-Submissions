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
    
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    
    bool isleaf(TreeNode* root)
    {
        if(root -> left == NULL && root -> right == NULL)
            return true;
        return false;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        vector<pair<int, int>> v;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto front= q.front();
                q.pop();
            
                if(isleaf(front))
                    v.push_back({front -> val, level});
                if(front -> left != NULL)
                    q.push(front -> left);
                if(front -> right != NULL)
                    q.push(front -> right);
            }
            level++;
        }
        sort(v.begin(), v.end(), cmp);
        int maxi = v[0].second;
        int sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].second == maxi)
                sum += v[i].first;
        }
        return sum;
    }
};