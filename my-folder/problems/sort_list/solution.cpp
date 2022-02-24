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
    
    
    
    ListNode* mergeLL(ListNode* head1, ListNode* head2)
    {
        ListNode* newhead = new ListNode(0);
        ListNode* newtail = newhead;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1 -> val <= head2 -> val)
            {
                newtail -> next = head1;
                newtail = newtail -> next;
                head1 = head1 -> next;
            }
            else
            {
                newtail -> next = head2;
                newtail = newtail -> next;
                head2 = head2 -> next;
            }
        }
        
        if(head1 == NULL)
            newtail -> next = head2;
        if(head2 == NULL)
            newtail -> next = head1;
        return newhead -> next;
    }
    
    ListNode* midLL(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* mid = midLL(head);
        ListNode* head1 = head;
        ListNode* temp = head;
        while(temp != mid)
        {
            temp = temp -> next;
        }
        ListNode* head2 = temp -> next;
        temp -> next = NULL;
        head1 = sortList(head1);
        head2 = sortList(head2);
        return mergeLL(head1,head2);
    }
};