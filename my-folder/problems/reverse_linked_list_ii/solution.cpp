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
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head -> next == NULL)
            return head;
        struct ListNode* list = reverseList(head -> next);
        struct ListNode* temp = list;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = head;
        head -> next = NULL;
        return list;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        if(left == 1)
        {
            ListNode* temp = head;
            int size = 0;
            while(head != NULL)
            {
                size++;
                head = head -> next;
            }
            if(size == right)
            {
                return reverseList(temp);
            }
            size = right - left + 1;
            while(temp2 -> next != NULL && --size)
            {
                temp2 = temp2 -> next;
            }
            ListNode* afterRight = temp2 -> next;
            temp2 -> next = NULL;
            ListNode* cutHead = reverseList(temp1);
            ListNode* temp3 = cutHead;
            while(cutHead -> next != NULL)
            {
                cutHead = cutHead -> next;
            }
            cutHead -> next = afterRight;
            return temp3;
        }
        
        
        
        ListNode* temp = temp1;
        int templeft = left;
        ListNode* prev = new ListNode(0);
        prev -> next = temp1;
        ListNode* ans = prev -> next;
        while(temp1 != NULL && --templeft)
        {
            prev = prev -> next;
            temp1 = temp1 -> next;
        }
        //cout<<head -> val;
        ListNode* cutList = temp1;
        int size = right-left+1;
        while(temp1 -> next != NULL && --size)
        {
            //cout<<size;
            temp1 = temp1 -> next;
        }
        //cout<<head -> val;
        ListNode* afterRight = temp1 -> next;
        //cout<<afterRight -> val;
        temp1 -> next = NULL;
        
        ListNode* cutHead = reverseList(cutList);
        
        if(cutHead != NULL)
        {
            prev -> next = cutHead;
            while(cutHead -> next != NULL)
            {
                cutHead = cutHead -> next;
            }
            cutHead -> next = afterRight;
        }
        return ans;
    }
};