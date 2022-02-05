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
    ListNode* middleNode(ListNode* head) {
        /*
        struct ListNode* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp -> next;
        }
        //cout<<count;
        int mid = (count/2) + 1;
        count = 1;
        //cout<<mid;
        while(head != NULL && count < mid)
        {
            head = head -> next;
            count++;
        }
        return head;
        */
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast -> next == NULL)
        {
            return slow;
        }
        return slow -> next;
    }
};