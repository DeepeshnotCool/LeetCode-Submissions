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
    ListNode* reverseLL(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        if(head -> next == NULL)
            return head;
        struct ListNode* list = reverseLL(head -> next);
        struct ListNode* temp = list;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = head;
        head -> next = NULL;
        return list;
    }
    
    ListNode* addTwoNumbers(ListNode* l11, ListNode* l22) {
        
        ListNode* l1 = reverseLL(l11);
        ListNode* l2 = reverseLL(l22);
        long long sum = 0, carry = 0;
        struct ListNode *ansList = new ListNode(0);
        struct ListNode *ansR = ansList;
        while(l1 != NULL && l2 != NULL)
        {
            sum = l1 -> val + l2 -> val + carry;
            carry = sum/10;
            struct ListNode *temp = new ListNode(sum%10);
            ansList -> next = temp;
            ansList = ansList -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL)
        {
            sum = l1 -> val + carry;
            carry = sum/10;
            struct ListNode *temp = new ListNode(sum%10);
            ansList -> next = temp;
            ansList = ansList -> next;
            l1 = l1 -> next;
        }
        while(l2 != NULL)
        {
            sum = l2 -> val + carry;
            carry = sum/10;
            struct ListNode *temp = new ListNode(sum%10);
            ansList -> next = temp;
            ansList = ansList -> next;
            l2 = l2 -> next;
        }
        if(carry)
        {
            struct ListNode *temp = new ListNode(carry);
            ansList -> next = temp;
            ansList = ansList -> next; 
        }
        ListNode* ans = reverseLL(ansR -> next);
        return ans;    
    }
};