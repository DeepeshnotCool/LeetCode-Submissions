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
    void reverseList(struct ListNode** headref){
        struct ListNode* current = *headref;
        struct ListNode* prev = NULL;
        struct ListNode* next;
        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *headref = prev;
    }
    
    void delhelper(struct ListNode* head){
        struct ListNode* current = head;
        struct ListNode* maxnode = head;
        struct ListNode* temp;

        while (current != NULL && current->next != NULL) {
            if (current->next->val < maxnode->val) 
            {
                temp = current->next;
                current->next = temp->next;
            }

            else
            {
                current = current->next;
                maxnode = current;
            }
        }
    }
    
    void helper(struct ListNode** head_ref){
        reverseList(head_ref);
        delhelper(*head_ref);
        reverseList(head_ref);
    }
    
    ListNode* removeNodes(ListNode* head) {
        helper(&head);
        return head;
    }
};