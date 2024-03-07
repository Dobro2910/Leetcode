package Medium.Intervals;

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class mergeIntervals {
    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) {
            return intervals;
        }
        
        // Sort the intervals based on the start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        
        List<int[]> mergedIntervals = new ArrayList<>();
        int[] currentInterval = intervals[0];
        
        for (int i = 1; i < intervals.length; i++) {
            int[] interval = intervals[i];
            if (interval[0] <= currentInterval[1]) {
                // Overlapping intervals, merge them
                currentInterval[1] = Math.max(currentInterval[1], interval[1]);
            } else {
                // Non-overlapping interval, add currentInterval to the result list
                mergedIntervals.add(currentInterval);
                currentInterval = interval;
            }
        }
        
        // Add the last interval
        mergedIntervals.add(currentInterval);
        
        // Convert list to array
        return mergedIntervals.toArray(new int[mergedIntervals.size()][]);
    }
}
