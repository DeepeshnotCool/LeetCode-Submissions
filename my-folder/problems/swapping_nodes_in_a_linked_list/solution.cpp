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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        while(head != NULL){
            v.push_back(head -> val);
            head = head -> next;
        }
        
        int temp = v[k-1];
        v[k-1] = v[v.size()-k];
        v[v.size()-k] = temp;
        
        ListNode* newnode = new ListNode(0);
        ListNode* ans = newnode;
        for(auto it : v){
            ListNode* temp = new ListNode(it);
            newnode -> next = temp;
            newnode = newnode -> next;
        }
        return ans -> next;
        
        
        
    }
};