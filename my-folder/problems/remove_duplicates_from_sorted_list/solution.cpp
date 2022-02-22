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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* ansList = new ListNode(head -> val);
        ListNode* ans = ansList;
        int prev = head -> val;
        //head = head -> next;
        while(head != NULL)
        {
            if(head -> val != prev)
            {
                ListNode* node = new ListNode(head -> val);
                ansList -> next = node;
                ansList = ansList -> next;
            }
            prev = head -> val;
            head = head -> next;
        }
        return ans;
    }
};