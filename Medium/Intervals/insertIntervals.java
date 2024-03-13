import java.util.ArrayList;
import java.util.List;

public class insertIntervals {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int frontInterval = newInterval[0];
        int endInterval = newInterval[1];

        ArrayList<ArrayList<Integer>> arrayList2D = new ArrayList<>();
        ArrayList<Integer> addArray = new ArrayList<>();
        boolean Continue = false;
        boolean Finished = false;

        if (intervals == null || intervals.length == 0) {
            int[][] result = new int[1][2];
            result[0][0] = newInterval[0];
            result[0][1] = newInterval[1];
            return result;
        } else if (newInterval == null || newInterval.length == 0) {
            return intervals;
        }

        for (int i = 0; i < intervals.length; i++) {
            // Scenario 4
            if ((newInterval[1] < intervals[i][0] && i == 0) || (newInterval[1] < intervals[i][0] && newInterval[0] > intervals[i-1][1])) {
                addArray.add(newInterval[0]);
                addArray.add(newInterval[1]);
                arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
                Finished = true;
            } else if (newInterval[0] > intervals[i][1] && i == intervals.length - 1) {
                arrayList2D.add(new ArrayList<>(List.of(intervals[i][0], intervals[i][1])));
                addArray.add(newInterval[0]);
                addArray.add(newInterval[1]);
                arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
                break;
            }

            // Scenario 1
            if (newInterval[0] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                return intervals;
            }

            // Scenario 2 and 3 
            if (frontInterval < intervals[i][0] && Finished == false) {
                Continue = true;
            } else if (intervals[i][0] <= frontInterval && frontInterval <= intervals[i][1]) {
                frontInterval = intervals[i][0];
                Continue = true;
            } 

            if (newInterval[1] < intervals[i][0] && Finished == false) {
                addArray.add(frontInterval);
                addArray.add(endInterval);
                arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
                Continue = false;
                Finished = true;
            } else if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                endInterval = intervals[i][1];
                addArray.add(frontInterval);
                addArray.add(endInterval);
                arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
                Continue = false;
                Finished = true;
                continue;
            } else if (i == intervals.length - 1 && newInterval[1] > intervals[i][1] && Continue == true) {
                addArray.add(frontInterval);
                addArray.add(endInterval);
                arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
                break;
            }

            if (Continue) {
                continue;
            }

            arrayList2D.add(new ArrayList<>(List.of(intervals[i][0], intervals[i][1])));
        }

        // Convert 2D ArrayList to 2D array
        int[][] result = new int[arrayList2D.size()][2];
        for (int i = 0; i < arrayList2D.size(); i++) {
            result[i][0] = arrayList2D.get(i).get(0);
            result[i][1] = arrayList2D.get(i).get(1);
        }

        return result;
    }
}

// Improve version
// if (intervals == null || intervals.length == 0) {
//     return new int[][]{newInterval};
// }

// List<int[]> mergedIntervals = new ArrayList<>();
// int index = 0;
// int start = newInterval[0];
// int end = newInterval[1];

// // Add intervals before newInterval
// while (index < intervals.length && intervals[index][1] < start) {
//     mergedIntervals.add(intervals[index]);
//     index++;
// }

// // Merge overlapping intervals
// while (index < intervals.length && intervals[index][0] <= end) {
//     start = Math.min(start, intervals[index][0]);
//     end = Math.max(end, intervals[index][1]);
//     index++;
// }
// mergedIntervals.add(new int[]{start, end});

// // Add remaining intervals
// while (index < intervals.length) {
//     mergedIntervals.add(intervals[index]);
//     index++;
// }

// return mergedIntervals.toArray(new int[mergedIntervals.size()][2]);
