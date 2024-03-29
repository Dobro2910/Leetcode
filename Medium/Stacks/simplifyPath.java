package Medium.Stacks;

import java.util.Stack;

public class simplifyPath {
    public String simplifyPath(String path) {
        Stack<Character> stack = new Stack<>();
        String canonicalPathResult = "";
        int doubleDotTime = 0;

        for (int i = 0; i < path.length(); i++) {
            stack.push(path.charAt(i));
        }

        while (!stack.isEmpty()) {
            char character = stack.pop();
            String singlePathString = "";

            // get single path of the string every time
            while (character != '/') {
                singlePathString = character + singlePathString;
                if (stack.isEmpty()) {
                    break;
                }
                character = stack.pop();
            }
            singlePathString = character + singlePathString;

            // check if the path is only a "/" or a "/.", ignore
            if (singlePathString.equals("/")) {
                continue;
            } else if (singlePathString.equals("/.")) {
                continue;
            }

            // check the path if its a double dot
            if (singlePathString.equals("/..")) {
                doubleDotTime++;
                continue;
            }

            if (doubleDotTime != 0) {
                doubleDotTime--;
                continue;
            }

            // add the current single path to the main path
            canonicalPathResult = singlePathString + canonicalPathResult;
        }

        if (canonicalPathResult.isEmpty()) {
            return "/";
        }

        return canonicalPathResult;
    }
}
