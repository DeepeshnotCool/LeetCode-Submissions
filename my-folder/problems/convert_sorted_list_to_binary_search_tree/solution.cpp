/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
     TreeNode* helper(vector<int>& nums, int left, int right, int index)
     {
        if(left > right)
            return NULL;
        index = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[index]);
        root -> left = helper(nums, left, index-1, index);
        root -> right = helper(nums, index + 1, right, index);
        return root;
     }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head != NULL)
        {
            v.push_back(head -> val);
            head = head -> next;
        }
        return helper(v,0,v.size()-1, -1);   
        
    }
};