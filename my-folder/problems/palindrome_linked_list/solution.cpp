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
    
    // ListNode* reverse(ListNode* head){
    //     if(head == NULL || head -> next == NULL)
    //         return head;
        
        
    //     ListNode* temp = reverse(head -> next);
    //     ListNode* ans = temp;
    //     while(temp -> next != NULL){
    //         temp = temp -> next;
    //     }
    //     temp -> next = head;
    //     head -> next = NULL;
    //     return ans;
        
    // }

    // ListNode* copyList(ListNode *L) {
    //     ListNode *current = L;
    //     ListNode *copy = new ListNode;
    //     copy->val = current->val;
    //     copy->next = NULL;

    //     ListNode *const head = copy;
    //     current = current->next;

    //     while (current != NULL) {
    //         copy = copy->next = new ListNode;
    //         copy->val = current->val;
    //         copy->next = NULL;
    //         current = current->next;
    //     }
    //     return head;
    // }


    ListNode* temp2 = NULL;
    void helper(ListNode* temp, bool &flag){
        if(temp == NULL)
            return;
        helper(temp->next,flag); 
        if(temp2 -> val != temp->val){
            flag = false;
            return;
        }
        temp2 = temp2->next;
    }

    bool isPalindrome(ListNode* head) {
        temp2 = head;
        ListNode* temp = head;
        bool flag = true;
        helper(temp, flag);
        return flag;

        // ListNode *temp = copyList(head);
        // ListNode* rev = reverse(temp);
        // // while(temp != NULL){
        // //     cout<<temp->val<<endl;
        // //     temp = temp -> next;
        // // }
        // while(head != NULL && rev != NULL){
        //     cout<<head->val<<" "<<rev->val<<endl;
        //     if(head -> val != rev -> val)
        //         return false;
        //     head = head -> next;
        //     rev = rev -> next;
        // }
        // return true;
    }
};

