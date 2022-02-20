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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        head = head -> next;
        int sum = 0;
        while(head != NULL)
        {  
           // cout<<temp->val;
            if(head -> val == 0)
            {
                ListNode* temp1 = new ListNode(sum);
                temp -> next = temp1;
                temp = temp -> next;
                //cout<<temp->val;
                sum = 0;
            }
            sum += head -> val;
            head = head -> next;
        }
        return ans -> next;
        
        
        
        
    }
};