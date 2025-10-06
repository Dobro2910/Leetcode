class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int maxRow = board.size();
        int maxCol = board[0].size();

        vector<vector<int>> newBoard(maxRow, vector<int>(maxCol, 0));

        for (int i = 0; i < maxRow; ++i) {
            for (int j = 0; j < maxCol; ++j) {
                int nw = (i > 0 && j > 0) ? board[i-1][j-1] : 0;
                int n  = (i > 0) ? board[i-1][j] : 0;
                int ne = (i > 0 && j < maxCol-1) ? board[i-1][j+1] : 0;
                int e  = (j < maxCol-1) ? board[i][j+1] : 0;
                int se = (i < maxRow-1 && j < maxCol-1) ? board[i+1][j+1] : 0;
                int s  = (i < maxRow-1) ? board[i+1][j] : 0;
                int sw = (i < maxRow-1 && j > 0) ? board[i+1][j-1] : 0;
                int w  = (j > 0) ? board[i][j-1] : 0;


                int total = nw + n + ne + e + se + s + sw + w;

                if (total < 2 && board[i][j] == 1) {
                    newBoard[i][j] = 0;
                } else if (total > 1 && total < 4 && board[i][j] == 1) {
                    newBoard[i][j] = 1;
                } else if (total > 3 && board[i][j] == 1) {
                    newBoard[i][j] = 0;
                } else if (total == 3 && board[i][j] == 0) {
                    newBoard[i][j] = 1;
                }
            }
        }

        board = newBoard;
    }
};