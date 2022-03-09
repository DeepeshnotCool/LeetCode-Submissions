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
    ListNode* deleteDuplicates(ListNode* head){
        map<int, int> m;
        while(head != NULL)
        {
            m[head -> val]++;
            head = head -> next;
        }
        head = new ListNode(0);
        ListNode* temp = head;
        for(auto it : m)
        {
            if(it.second > 1)
                continue;
            ListNode* newNode = new ListNode(it.first);
            head -> next = newNode;
            head = head -> next;
        }
        return temp -> next;
    }
};