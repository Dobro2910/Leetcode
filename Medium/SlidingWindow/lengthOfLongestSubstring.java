package Medium.SlidingWindow;

public class lengthOfLongestSubstring {
    public int lengthOfLongestSubstring(String s) {
        int i = 0;
        int j = 1;
        int count = 1;
        int longestCount = 1;

        if (s.isEmpty()) {
            return 0;
        }

        while (j != s.length()) {
            for (int k = i; k < j; k++) {
                if (s.charAt(k) == s.charAt(j)) {
                    i++;
                    if (longestCount < count) {
                        longestCount = count;
                    }
                    j--;
                    count = count - 2;
                    break;
                }
            }
            j++;
            count++;
        }

        if (longestCount < count) {
            longestCount = count;
        }

        return longestCount;
    }
}
