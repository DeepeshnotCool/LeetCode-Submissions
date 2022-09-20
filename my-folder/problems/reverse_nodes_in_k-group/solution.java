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
    public ListNode reverseKGroup(ListNode head, int k) {
        
        if(k == 1)
            return head;
        
        int i=0;
        int length = length(head);
        ListNode h = null;
        ListNode  prev = null;
         ListNode pres = head;
         ListNode nex = head.next;
        ListNode d = null;
        
        while(i < length/k)
        {   
            int j=0;
             if( i != 0)
            { 
              d = prev;
            }
            // if(prev != null)
            //     System.out.println(j + " " + prev.val);
            // System.out.println(j + " " + pres.val);
            // System.out.println(j + " " + nex.val);
            while(pres != null && j<k)
            {
                pres.next = prev;
                prev = pres;
                pres = nex;
                if(nex.next != null)
                    nex = nex.next;
                // System.out.println(j + " " + prev.val);
                // System.out.println(j + " " + pres.val);
                // System.out.println(j + " " + nex.val);
                j++;
            }
            if(i == 0)
                h = prev;
           // if(j == length)
           //     return h;
            if(d != null)
            {  
                d.next = prev;
            }
            ListNode temp = prev;
            int l = 0;
            while(l < k-1){
                temp = temp.next;
                l++;
            }
            prev = temp;
            i++;
        }
        prev.next = pres;
        
        if(length % k == 0){
            ListNode ans = h;
            int v = 0;
            while(v < length-1){
                ans = ans.next;
                v++;
            }
            ans.next = null;
            return h;
        }
      return h;   
    }
    private static int length(ListNode head)
    {
        ListNode f = head;
        int len = 0;
        while( f!= null)
        {
            f = f.next;
            len++;
        }
        return len;
    }
}