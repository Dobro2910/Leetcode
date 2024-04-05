package Easy.LinkedList;

public class linkedListCycle {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false; // If the list is empty or has only one node, there's no cycle.
        }

        ListNode slow = head;
        ListNode fast = head.next;

        while (fast != null && fast.next != null) {
            if (slow == fast) {
                return true; // If the slow and fast pointers meet, there's a cycle.
            }
            slow = slow.next; // Move slow pointer one step.
            fast = fast.next.next; // Move fast pointer two steps.
        }

        return false; // If the fast pointer reaches the end of the list, there's no cycle.
    }
}
