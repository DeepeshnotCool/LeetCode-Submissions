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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* newleft = left;
        ListNode* right = new ListNode(0);
        ListNode* newright = right;
        while(head != NULL){
            if(head -> val < x){
                ListNode* temp = new ListNode(head -> val);
                left -> next = temp;
                left = left -> next;
            }
            else{
                ListNode* temp = new ListNode(head -> val);
                right -> next = temp;
                right = right -> next;
            }
            head = head -> next;
        }
        
        newright = newright -> next;
        left -> next = newright;
        return newleft -> next;
        
        
        
    }
};