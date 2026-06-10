class Solution {
public:
    bool dfs(vector<vector<char>>& board,
             string& word,
             int row,
             int col,
             int index,
             vector<vector<int>>& vis) {

        if(index == word.length())
            return true;

        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size())
            return false;

        if(vis[row][col])
            return false;

        if(board[row][col] != word[index])
            return false;

        vis[row][col] = 1;

        bool found =
            dfs(board, word, row - 1, col, index + 1, vis) ||
            dfs(board, word, row + 1, col, index + 1, vis) ||
            dfs(board, word, row, col - 1, index + 1, vis) ||
            dfs(board, word, row, col + 1, index + 1, vis);

        vis[row][col] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(board[i][j] == word[0]) {

                    if(dfs(board, word, i, j, 0, vis))
                        return true;
                }
            }
        }

        return false;
    }
};