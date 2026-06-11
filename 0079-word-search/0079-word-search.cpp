class Solution {
    bool solve(vector<vector<char>>& board, string& word,
               int row, int col, int index) {

        if(index == word.size()) {
            return true;
        }

        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size() ||
           board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        bool found =
            solve(board, word, row + 1, col, index + 1) ||
            solve(board, word, row - 1, col, index + 1) ||
            solve(board, word, row, col + 1, index + 1) ||
            solve(board, word, row, col - 1, index + 1);

        board[row][col] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(solve(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};