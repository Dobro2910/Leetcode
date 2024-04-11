package Medium.LinkedList;

public class deepCopy {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;

        // hashmap to keep track of original linked list nodes and their corresponding
        // copies
        Map<Node, Node> nodeMap = new HashMap<>();

        // Create a copy of the head node
        Node headCopy = new Node(head.val);
        nodeMap.put(head, headCopy);

        Node current = head;
        Node currentCopy = headCopy;

        // Iterate through the linked list
        while (current != null) {
            // Copy next node if not already copied
            if (current.next != null && !nodeMap.containsKey(current.next)) {
                nodeMap.put(current.next, new Node(current.next.val));
            }
            // Copy random node if not already copied
            if (current.random != null && !nodeMap.containsKey(current.random)) {
                nodeMap.put(current.random, new Node(current.random.val));
            }

            // Set next and random pointers for the copy
            currentCopy.next = nodeMap.get(current.next);
            currentCopy.random = nodeMap.get(current.random);

            // Move to the next nodes
            current = current.next;
            currentCopy = currentCopy.next;
        }

        return headCopy;
    }
}