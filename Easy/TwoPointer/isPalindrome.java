package Easy.TwoPointer;

public class isPalindrome {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        s = s.replaceAll(
            "[^a-zA-Z0-9]", "");

        Boolean isEven = false;
        Boolean palindrome = true;
        int i = 0;
        int j = s.length() - 1;

        if (s.length()%2 == 0) {
            isEven = true;
        } 

        if (isEven == true) {
            while (i < s.length()/2) {
                if (s.charAt(i) != s.charAt(j)) {
                    palindrome = false;
                }
                i++;
                j--;
            }
        } else {
            while (i < s.length()/2) {
                if (s.charAt(i) != s.charAt(j)) {
                    palindrome = false;
                }
                i++;
                j--;
            }
        }

        return palindrome;
    }
}
