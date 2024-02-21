import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<Character> numberCheckSet = new HashSet<>(Arrays.asList('1', '2', '3', '4', '5', '6', '7', '8', '9'));

        // Check Row
        for (int i = 0; i < 9; i++) {
            if (!isValidSet(board[i], numberCheckSet)) {
                return false;
            }
        }

        // Check Col
        for (int i = 0; i < 9; i++) {
            char[] colArray = new char[9];
            for (int j = 0; j < 9; j++) {
                colArray[j] = board[j][i];
            }
            if (!isValidSet(colArray, numberCheckSet)) {
                return false;
            }
        }

        // Check 3x3
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidSet(get3x3Array(board, i, j), numberCheckSet)) {
                    return false;
                }
            }
        }

        return true;
    }

    private boolean isValidSet(char[] set, Set<Character> numberCheckSet) {
        Set<Character> setCopy = new HashSet<>(numberCheckSet);
        
        for (char c : set) {
            if (c != '.' && !setCopy.remove(c)) {
                return false;
            }
        }

        return true;
    }

    private char[] get3x3Array(char[][] board, int row, int col) {
        char[] result = new char[9];
        int index = 0;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                result[index++] = board[i][j];
            }
        }
        return result;
    }
}