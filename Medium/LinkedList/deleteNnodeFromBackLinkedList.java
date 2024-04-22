package Medium.LinkedList;

public class deleteNnodeFromBackLinkedList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode currentNode = head;
        int listLength = 1;

        while (currentNode != null) {
            currentNode = currentNode.next;
            listLength++;
        }

        int destination = listLength - n;

        if (destination == 1) {
            head = head.next;
            return head;
        }

        int i = 1;
        currentNode = head;
        ListNode backNode = null;

        while (currentNode != null) {
            if (i != destination) {
                backNode = currentNode;
                currentNode = currentNode.next;
            } else {
                backNode.next = currentNode.next;
                break;
            }
            i++;
        }

        return head;
    }
}
