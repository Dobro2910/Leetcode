package Easy.Stack;

import java.util.Stack;

public class validParentheses {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        if (s.length() < 2) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                stack.push(s.charAt(i));
            } else if (stack.isEmpty()) {
                return false;
            } else if (s.charAt(i) == ')') {
                char top = stack.pop();
                if (top != '(') {
                    return false;
                }
            } else if (s.charAt(i) == '}') {
                char top = stack.pop();
                if (top != '{') {
                    return false;
                }
            } else if (s.charAt(i) == ']') {
                char top = stack.pop();
                if (top != '[') {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (!stack.isEmpty()) {
            return false;
        }

        return true;
    }
}
