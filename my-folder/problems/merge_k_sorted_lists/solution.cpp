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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i]!= NULL){
                v.push_back(lists[i] -> val);
                lists[i] = lists[i] -> next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* listNode = new ListNode(0);
        ListNode* ansList = listNode;
        for(auto it: v){
            ListNode* temp = new ListNode(it);
            listNode -> next = temp;
            listNode = listNode -> next;
        }
        return ansList -> next;
    }
};