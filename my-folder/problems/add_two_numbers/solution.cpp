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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        long long num1 = 0, num2 = 0;
        long long i = 0;
        while(l1 != NULL)
        {
            num1 += l1 -> val * pow(10,i);
            i++;
            l1 = l1 -> next;
        }
        i = 0;
        while(l2 != NULL)
        {
            num2 += l2 -> val * pow(10,i);
            i++;
            l2 = l2 -> next;
        }
        long long num = num1+num2;
        struct ListNode *l = new ListNode();
        struct ListNode *head = l;
        if(num == 0)
        {
            struct ListNode *ls1 = new ListNode(0);
            return ls1;
        }
        while(num != 0)
        {
            long long n = num%10;
            struct ListNode *lNext = new ListNode(n);
            l -> next = lNext;
            l = l -> next;
            num = num/10;
        }
        return head -> next;
        */
        
        long long sum = 0, carry = 0;
        struct ListNode *ansList = new ListNode(0);
        struct ListNode *ansR = ansList;
        while(l1 != NULL && l2 != NULL)
        {
            sum = l1 -> val + l2 -> val + carry;
            carry = sum/10;
            struct ListNode *temp = new ListNode(sum%10);
            ansList -> next = temp;
            ansList = ansList -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL)
        {
            sum = l1 -> val + carry;
            carry = sum/10;
            struct ListNode *temp = new ListNode(sum%10);
            ansList -> next = temp;
            ansList = ansList -> next;
            l1 = l1 -> next;
        }
        while(l2 != NULL)
        {
            sum = l2 -> val + carry;
            carry = sum/10;
            struct ListNode *temp = new ListNode(sum%10);
            ansList -> next = temp;
            ansList = ansList -> next;
            l2 = l2 -> next;
        }
        if(carry)
        {
            struct ListNode *temp = new ListNode(carry);
            ansList -> next = temp;
            ansList = ansList -> next; 
        }
        return ansR -> next;
        
        
        
        
        
        
        
        
        
    }
};