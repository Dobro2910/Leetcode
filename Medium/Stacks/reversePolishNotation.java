package Medium.Stacks;

import java.util.Stack;

public class reversePolishNotation {
    public void pushElementFunction(Stack<String> stack, String operator) {
        String elementString1 = stack.pop();
        String elementString2 = stack.pop();
        int element1 = Integer.parseInt(elementString1);
        int element2 = Integer.parseInt(elementString2);
        int pushElement = 0;

        switch (operator) {
            case "+":
                pushElement = element2 + element1;
                break;
            case "-":
                pushElement = element2 - element1;
                break;
            case "*":
                pushElement = element2 * element1;
                break;
            case "/":
                pushElement = element2 / element1;
                break;
        }

        stack.push(String.valueOf(pushElement));
    }

    public int evalRPN(String[] tokens) {
        Stack<String> stack = new Stack<>();

        for (String word : tokens) {
            if ((word.equals("+")
                    || word.equals("-")
                    || word.equals("*")
                    || word.equals("/"))
                    && stack.size() >= 2) {
                pushElementFunction(stack, word);
                continue;
            }
            stack.push(word);
        }

        return Integer.parseInt(stack.pop());
    }
}
