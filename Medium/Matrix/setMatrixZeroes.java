import java.util.ArrayList;

class Solution {
    public void setZeroes(int[][] matrix) {
        ArrayList<Integer> row = new ArrayList<>();
        ArrayList<Integer> col = new ArrayList<>();

        // add all 0 matrix value
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    row.add(i);
                    col.add(j);
                }
            }
        }

        // change row and column
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (row.contains(i) && col.contains(j)) {

                    for (int k = 0; k < matrix.length; k++) {
                        matrix[k][j] = 0;
                    }

                    for (int k = 0; k < matrix[0].length; k++) {
                        matrix[i][k] = 0;
                    }

                    row.remove(Integer.valueOf(i));
                    col.remove(Integer.valueOf(j));
                }
            }
        }
    }
}