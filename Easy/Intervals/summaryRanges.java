package Easy.Intervals;

import java.util.*;

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<>();
        int n = nums.length;
        if (n == 0) {
            return result;
        }
        
        int start = nums[0];
        int end = start;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                result.add(formatRange(start, end));
                start = nums[i];
                end = start;
            }
        }
        
        // Add the last range
        result.add(formatRange(start, end));
        
        return result;
    }

    private String formatRange(int start, int end) {
        if (start == end) {
            return String.valueOf(start);
        } else {
            return start + "->" + end;
        }
    }
}