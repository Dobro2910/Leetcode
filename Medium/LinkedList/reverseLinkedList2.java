package Medium.LinkedList;

public class reverseLinkedList2 {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (left == right) {
            return head;
        }

        ListNode backNode = null;
        ListNode currentNode = head;
        ListNode nextNode = null;

        ListNode startNode = null;
        ListNode endNode = null;

        boolean reverse = false;
        int i = 1;

        while (currentNode != null) {
            if (i == left) {
                reverse = true;
                startNode = backNode;
                endNode = currentNode;

                backNode = currentNode;
                currentNode = currentNode.next;
                i++;
                continue;
            }

            if (i == right) {
                if (startNode == null) {
                    endNode.next = currentNode.next;
                    currentNode.next = backNode;
                    head = currentNode;
                } else {
                    startNode.next = currentNode;
                    endNode.next = currentNode.next;
                    currentNode.next = backNode;
                }

                return head;
            }

            if (reverse == true) {
                nextNode = currentNode.next;
                currentNode.next = backNode;
                backNode = currentNode;
                currentNode = nextNode;
                i++;
                continue;
            }

            backNode = currentNode;
            currentNode = currentNode.next;
            i++;
        }

        return head;
    }
}
