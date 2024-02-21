class Solution {
    public void rotate(int[][] matrix) {
        transpose(matrix);
        reverseRows(matrix);
    }

    // switch the matrix down the diagonal line, revserse it by the diagonal line
    private void transpose(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap matrix[i][j] and matrix[j][i]
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    private void reverseRows(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                // Swap matrix[i][left] and matrix[i][right]
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;

                left++;
                right--;
            }
        }
    }
}
