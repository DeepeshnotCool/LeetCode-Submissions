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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        struct ListNode* temp = head;
        struct ListNode* prev = head;
        head = head -> next;
        while(head != NULL)
        {   
            int tempval = prev -> val;
            prev -> val = head -> val;
            head -> val = tempval;
            if(head -> next != NULL)
            {
                prev = prev -> next -> next;
                head = head -> next -> next;
            }
            else
                break;
        }
        return temp;
    }
};