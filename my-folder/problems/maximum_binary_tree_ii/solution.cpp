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
    TreeNode* helper(vector<int>& v, int left, int right, int index)
    {
        if(left > right)
            return NULL;
        int maxi = INT_MIN;
        for(int i = left; i <= right; i++)
        {
            if(v[i] > maxi)
            {
                maxi = v[i];
                index = i;
            }
        }
        //cout<<index<<" ";
        TreeNode* root = new TreeNode(v[index]);
        //cout<<root -> val<<endl;
        root -> left = helper(v, left, index-1, index);
        root -> right = helper(v, index + 1, right, index);
        return root;        
    }
    
    
    void inOrder(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
        {
            return;
        }
        inOrder(root -> left,v);
        v.push_back(root -> val);
        inOrder(root -> right,v);
    }
    
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> v;
        inOrder(root, v);
        v.push_back(val);
        return helper(v,0,v.size()-1,-1);   
    }
};