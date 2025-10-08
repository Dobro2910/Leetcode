import java.util.ArrayList;

public class findMinArrowsShot {
    public int findMinArrowShots(int[][] points) {
        int count = 0;
        ArrayList<int[]> pointsList = new ArrayList<>();

        // Add elements of points array to pointsList
        for (int i = 0; i < points.length; i++) {
            pointsList.add(points[i]);
        }

        // Iterate over pointsList
        for (int i = 0; i < pointsList.size(); i++) {
            int[] currentPoint = pointsList.get(i);
            int front = currentPoint[0];
            int end = currentPoint[1];
            
            // Iterate over pointsList again to find elements to remove
            for (int j = i; j < pointsList.size(); j++) {
                int[] innerPoint = pointsList.get(j);

                // scenario 1
                if (innerPoint[0] <= front && innerPoint[1] >= end) {
                    pointsList.remove(j);
                    System.out.println("[" + innerPoint[0] + "," + innerPoint[1] + "]" + " 1");
                    j--;
                    continue;
                }
                // scenario 2
                if (innerPoint[0] <= front && innerPoint[1] >= front) {
                    pointsList.remove(j);
                    System.out.println("[" + innerPoint[0] + "," + innerPoint[1] + "]" + " 2");
                    j--;
                    continue;
                }
                // scenario 3
                if (innerPoint[0] <= end && innerPoint[1] >= end) {
                    pointsList.remove(j);
                    System.out.println("[" + innerPoint[0] + "," + innerPoint[1] + "]" + " 3");
                    j--;
                    continue;
                }

                // scenario 4
                if (innerPoint[0] > front && innerPoint[1] < end) {
                    pointsList.remove(j);
                    System.out.println("[" + innerPoint[0] + "," + innerPoint[1] + "]" + " 4");
                    j--;
                    continue;
                }
            }

            System.out.println("---------------------------------------------------------------------");

            // Increment the count
            count++;
            i--; // Decrement i to recheck the current index after removal
        }

        return count;
    }
}
