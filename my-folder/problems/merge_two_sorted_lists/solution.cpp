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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode* l = new ListNode();
        struct ListNode* head = l;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1 -> val < list2 -> val)
            {
                struct ListNode* temp = new ListNode(list1 -> val);
                l -> next = temp;
                l = l -> next;
                list1 = list1 -> next;
            }
            else
            {
                struct ListNode* temp = new ListNode(list2 -> val);
                l -> next = temp;
                l = l -> next;
                list2 = list2 -> next;
            }
        }
        while(list1 != NULL)
        {
            struct ListNode* temp = new ListNode(list1 -> val);
            l -> next = temp;
            l = l -> next;
            list1 = list1 -> next;
        }
        while(list2 != NULL)
        {
            struct ListNode* temp = new ListNode(list2 -> val);
            l -> next = temp;
            l = l -> next;
            list2 = list2 -> next;
        }
        return head -> next;
    }
};