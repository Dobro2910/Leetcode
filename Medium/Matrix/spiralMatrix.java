import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<Integer> spiralOrder(int[][] matrix) {
        int rowStart = 0;
        int colStart = 0;

        int rowEnd = matrix.length;
        int colEnd = matrix[0].length;

        String dir = "right";

        // Create a new ArrayList of integers
        ArrayList<Integer> integerList = new ArrayList<>();

        while(rowEnd > rowStart && colStart < colEnd) {
            if (dir == "right") {
                for (int i = colStart; i < colEnd; i++) {
                    integerList.add(matrix[rowStart][i]);
                }
                rowStart++;
                dir = "down";
            } else if (dir == "down") {
                for (int i = rowStart; i < rowEnd; i++) {
                    integerList.add(matrix[i][colEnd - 1]);
                }
                colEnd--;
                dir = "left";
            } else if (dir == "left") {
                for (int i = colEnd - 1; i >= colStart; i--) {
                    integerList.add(matrix[rowEnd - 1][i]);
                }
                rowEnd--;
                dir = "up";
            } else if (dir == "up") {
                for (int i = rowEnd - 1; i >= rowStart; i--) {
                    integerList.add(matrix[i][colStart]);
                }
                colStart++;
                dir = "right";
            }

            for (int value : integerList) {
                System.out.println(value);
            }
            System.out.println("------------------------------------------------------");
        }

        return integerList;
    }
}