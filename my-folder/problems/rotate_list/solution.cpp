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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)
            return head;
        vector<int> nums;
        while(head != NULL)
        {
            nums.push_back(head -> val);
            head = head -> next;
        }
        
        int n = nums.size();
        if(n < k)
            k = k%n;
        vector<int> v;
        for(int i = n-k; i < n; i++)
        {
            v.push_back(nums[i]);
            //nums.insert(nums.begin(), nums[n-1]);
            //nums.pop_back();
        }
        for(int i = 0; i < n-k; i++)
        {
            v.push_back(nums[i]);
        }
        nums = v;
        
        head = new ListNode(0);
        ListNode* temp = head;
        for(auto it : nums)
        {
            ListNode* newNode = new ListNode(it);
            head -> next = newNode;
            head = head -> next;
        }
        return temp -> next;
        
        
    }
};