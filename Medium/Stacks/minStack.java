package Medium.Stacks;

import java.util.ArrayList;

public class minStack {
    private ArrayList<Integer> myList = new ArrayList<>();
    private ArrayList<Integer> sortedList = new ArrayList<>();
    private int min = Integer.MAX_VALUE;

    public minStack() {
    }

    public void push(int val) {
        myList.add(val);
        if (val <= min) {
            min = val;
            sortedList.add(min);
        }
    }

    public void pop() {
        if (!myList.isEmpty() && myList.get(myList.size() - 1).equals(min)) {
            sortedList.remove(sortedList.size() - 1);
            if (!sortedList.isEmpty()) {
                min = sortedList.get(sortedList.size() - 1);
            } else {
                min = Integer.MAX_VALUE;
            }
        }
        myList.remove(myList.size() - 1);
    }

    public int top() {
        return myList.get(myList.size() - 1);
    }

    public int getMin() {
        return min;
    }
}
