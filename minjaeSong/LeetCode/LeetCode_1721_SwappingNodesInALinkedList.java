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
    public ListNode swapNodes(ListNode head, int k) {
        ArrayList<ListNode> arr = new ArrayList<ListNode>();
        int cnt = 1;
        while(head!=null){
            arr.add(head);
            head = head.next;
        }
        int tmp = arr.get(k-1).val;
        arr.get(k-1).val = arr.get(arr.size()-k).val;
        arr.get(arr.size()-k).val = tmp;

        return arr.get(0);     
    }
}