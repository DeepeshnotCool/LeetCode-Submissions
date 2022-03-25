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
    
    ListNode* helper(ListNode* head, int val){
        if(head == NULL)
            return head;
        
        ListNode* temp = helper(head -> next, val);
        if(head -> val == val){
            return temp;
        }
        head -> next = temp;
        return head;
    }
    
    
    
    ListNode* removeElements(ListNode* head, int val) {
        /*
        if(head == NULL)
            return NULL;
        struct ListNode* prev = head;
        //struct ListNode* temp = head;
        while(head != NULL)
        {
            if(head -> val != val)
                break;
            head = head -> next;
        }
        prev = head;
        if(head == NULL)
            return NULL;
        struct ListNode* temp = head;
        head = head -> next;
        while(head != NULL)
        {
            cout<<prev -> val<<" "<<head -> val<<endl;
            if(head -> val == val)
            {
                prev -> next = head -> next;
                head = head -> next;
            }
            prev = prev -> next;
            if(head != NULL)
                head = head -> next;
        }
        return temp;
        */
        
        return helper(head, val);
    }
};

