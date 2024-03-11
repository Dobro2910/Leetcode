public class insertIntervals {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int frontInterval = newInterval[0];
        int endInterval = newInterval[1];

        ArrayList<ArrayList<Integer>> arrayList2D = new ArrayList<>();
        ArrayList<Integer> addArray = new ArrayList<>();
        boolean Continue = false;

        for (int i = 0; i < intervals.length; i++) {
            // Scenario 1
            if (newInterval[0] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                arrayList2D.add(new ArrayList<>(List.of(intervals[i][0], intervals[i][1])));
            }

            // Scenario 2 and 3
            if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) {
                frontInterval = intervals[i][0];
                Continue = true;
                continue;
            }

            if (newInterval[1] <= intervals[i][0] && Continue == true) {
                addArray.add(frontInterval);
                addArray.add(endInterval);
                arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
            }
            
            if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                endInterval = intervals[i][1];

                if (Continue == true) {
                    addArray.add(frontInterval);
                    addArray.add(endInterval);

                    arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
                    Continue = false;
                    continue;
                } else {
                    addArray.add(frontInterval);
                    addArray.add(endInterval);

                    arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
                }
            }

            // Scenario 4
            if ((newInterval[1] < intervals[i][0] && i == 0) || (newInterval[1] < intervals[i][0] && newInterval[0] > intervals[i-1][1])) {
                addArray.add(newInterval[0]);
                addArray.add(newInterval[1]);
                arrayList2D.add(new ArrayList<>(List.copyOf(addArray)));
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
