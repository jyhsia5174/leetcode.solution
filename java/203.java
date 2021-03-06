// 203. Remove Linked List Elements
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
    public ListNode removeElements(ListNode head, int val) {
        ListNode sentinel = new ListNode(0);
        sentinel.next = head;
        
        ListNode prev = sentinel, curr = head;
        
        while( curr != null ){
            if( curr.val == val ) prev.next = curr.next;
            else prev = curr;
            curr = curr.next;
        }
        
        return sentinel.next;
    }
}


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
    public ListNode removeElements(ListNode head, int val) {
        
        ListNode newHead = head;
        while( newHead != null ){
            if( newHead.val != val ){
                break;
            }
            newHead = newHead.next;
        }
            
        if( newHead != null ){
            ListNode preNode = newHead;
            ListNode curNode = newHead.next;
            
            while( curNode != null ){
                if( curNode.val != val ) {
                    preNode.next = curNode;
                    preNode = curNode;
                }
                curNode = curNode.next;
            }
        
            preNode.next = null;
        }
        
        return newHead;
    }
}
