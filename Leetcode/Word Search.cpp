// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx) {
            int n = board.size();
            int m = board[0].size();

            if(idx == word.size()) return true;

            if(i < 0 or i >= n or j < 0 or j >= m or board[i][j] != word[idx]){
                return false;
            }

            char temp = board[i][j];
            board[i][j] = '#'; // to avoid revisiting same cell

            bool found = dfs(board, word, i + 1, j, idx + 1) or
            dfs(board, word, i - 1, j, idx + 1) or 
            dfs(board, word, i, j + 1, idx + 1) or
            dfs(board, word, i, j - 1, idx + 1);

            board[i][j] = temp;

            return found;
        }


    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};