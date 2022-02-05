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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp -> next;
        }
        if(count == n)
        {
            return head -> next;
        }
        if(count == 1)
            return NULL;    
        //cout<<count;
        n = count-n;
        count = 0;
        //cout<<mid;
        struct ListNode* temp1 = head;
        struct ListNode* temp11 = temp1;
        while(temp1 != NULL && count < n-1)
        {
            //cout<<count<<"-"<<temp1->val<<endl;
            temp1 = temp1 -> next;
            count++;
        }
        //cout<<temp1->val;
        head = temp1 -> next;
        temp1 -> next = head -> next;
        return temp11;
    }
};