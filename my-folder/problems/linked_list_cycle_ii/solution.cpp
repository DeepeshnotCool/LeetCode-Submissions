/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        map<ListNode*, int> m;
        while(head != NULL){
            m[head]++;
            head = head -> next;
            if(m[head] == 2)
                return head;
        }
        return NULL;
        
        
        
    }
};

