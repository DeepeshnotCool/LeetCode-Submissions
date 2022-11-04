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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* ansOdd = odd;
        ListNode* even = new ListNode(0);
        ListNode* ansEven = even;
        bool flag = true;
        while(head != NULL){
            if(flag){
                odd -> next = new ListNode(head -> val);
                odd = odd -> next;
            } else{
                even -> next = new ListNode(head -> val);
                even = even -> next;
            }
            flag = !flag;
            head = head -> next;
        }
        odd -> next = ansEven -> next;
        return ansOdd -> next;
    }
};