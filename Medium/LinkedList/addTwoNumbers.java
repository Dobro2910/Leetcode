package Medium.LinkedList;

public class addTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sumOutput = new ListNode();
        ListNode headSumOutput = sumOutput; // Keep a reference to the head of the result list
        int inputVal = 0;
        int remember = 0;

        while (l1 != null || l2 != null) {
            int val1 = (l1 != null) ? l1.val : 0;
            int val2 = (l2 != null) ? l2.val : 0;

            if ((val1 + val2 + remember) >= 10) {
                inputVal = (val1 + val2 + remember) - 10;
                remember = 1;

                ListNode newNode = new ListNode(inputVal);
                sumOutput.next = newNode;
                sumOutput = sumOutput.next;
            } else {
                inputVal = val1 + val2 + remember;

                ListNode newNode = new ListNode(inputVal);
                sumOutput.next = newNode;
                sumOutput = sumOutput.next;
                remember = 0;
            }

            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }

        if (remember == 1) {
            ListNode newNode = new ListNode(1);
            sumOutput.next = newNode;
            sumOutput = sumOutput.next;
            remember = 0;
        }

        return headSumOutput.next;
    }
}
