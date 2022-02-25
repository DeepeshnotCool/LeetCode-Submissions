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
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    void pushAll(TreeNode* root)
    {
        while(root != NULL)
        {
            s.push(root);
            root = root -> left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        if(!s.empty())
        {
            auto node = s.top();
            s.pop();
            if(node != NULL)
            {
                pushAll(node -> right);
                return node -> val;
            }
            else
                return NULL;
        }
        else
            return NULL;
    }
    
    bool hasNext() {
        if(!s.empty())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */