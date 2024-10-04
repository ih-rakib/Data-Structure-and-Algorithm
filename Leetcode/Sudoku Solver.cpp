// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    private:
        bool solve(vector<vector<char>>& board){
            // traverse the board to find empty cells
            for(int i = 0; i < 9; ++i) {
                for(int j = 0; j < 9; ++j) {
                    if(board[i][j] == '.'){
                        // try to place a digit from 1 to 9
                        for(char num = '1'; num <= '9'; ++num){
                            // for each digit check if it's valid placing by ensuring it's not in same row, col, or 3x3 sub-box
                            if(isValid(board, i, j, num)){
                                // place the number
                                board[i][j] = num;
                                // recursively try to fill the rest of the board now
                                if(solve(board)) {
                                    return true;
                                }
                                // backtrack if it leads to no solution
                                board[i][j] = '.';
                            }
                        }
                        // if no number is placed in this cell - return false
                        return false;
                    }
                }
            }
            return true; // means entire board is filled correctly
        }

        bool isValid(vector<vector<char>>& board, int row, int col, char num) {
            // check row
            for(int i = 0; i < 9; ++i) {
                if(board[row][i] == num) return false;
            }

            // check col
            for(int j = 0; j < 9; ++j) {
                if(board[j][col] == num) return false;
            }

            // check 3 x 3 sub-box
            int subBoxRow = (row/3)*3; // starting row of each 3 x 3 sub-box
            int subBoxCol = (col/3)*3; // starting col of each 3 x 3 sub-box

            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(board[i+subBoxRow][j+subBoxCol] == num) {
                        return false;
                    }
                }
            }
            return true;
        }
};