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
    // TreeNode* helper(vector<int>& preorder, int s, int e)
    // {
    //     if(s > e)
    //     {
    //         return NULL;
    //     }
    //     int rootData = preorder[s];
    //     int index = -1;
    //     for(int i = s; i <= e; i++)
    //     {
    //         if(preorder[i] > rootData)
    //         {
    //             index = i;
    //             break;
    //         }
    //     }
    //     int l_s = s+1;
    //     int l_e = index-1;
    //     int r_s = index;
    //     int r_e = e;
    //     TreeNode* root = new TreeNode(rootData);
    //     root -> left = helper(preorder, l_s, l_e);
    //     root -> right = helper(preorder, r_s, r_e);
    //     return root;
    // }
    
    TreeNode* helper(vector<int>& preorder, int &index, int upper_limit)
    {
        if(index == preorder.size() || preorder[index] > upper_limit)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root -> left = helper(preorder, index, root -> val);
        root -> right = helper(preorder, index , upper_limit);
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //return helper(preorder, 0, preorder.size()-1);
        int index = 0;
        return helper(preorder, index, INT_MAX);
    }
};


