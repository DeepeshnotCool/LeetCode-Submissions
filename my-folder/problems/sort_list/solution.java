/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if(head== null || head.next == null)
            return head;
            ListNode mid = getmid(head);
        ListNode left = sortList(head);
        ListNode right = sortList (mid);
        
       return merge(left, right);
    }
    ListNode getmid(ListNode head)
        {
        ListNode midprev = null;
        
        while(head != null && head.next != null)
            {
            midprev = (midprev==null) ?head : midprev.next;
            head = head.next.next;
        }
        ListNode mid = midprev.next;
        midprev.next = null;
        return mid;
    }
    
    ListNode merge(ListNode list1, ListNode list2)
        {
        ListNode ans = new ListNode();
        ListNode temp = ans;
        while(list1 != null && list2 != null)
            {
            if(list1.val < list2.val)
                {
                temp.next = list1;
                list1 = list1.next;
                
            }
            else{
                temp.next = list2;
                list2= list2.next;
                
                }
            temp = temp.next;
        }
        while(list1 !=null)
            {
            temp.next = list1;
            list1 = list1.next;
            temp =temp.next;
        }
        while(list2 !=null)
            {
            temp.next = list2;
            list2 = list2.next;
            temp = temp.next;
        }
        return ans.next;
        }
}