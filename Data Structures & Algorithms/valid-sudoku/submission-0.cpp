class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                int box = (i / 3) * 3 + (j / 3);
                if(board[i][j]=='.'){
                    continue;
                }
                if(rows[i].find(board[i][j])==rows[i].end()&&boxes[box].find(board[i][j])==boxes[box].end()&&cols[j].find(board[i][j])==cols[j].end()){
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[box].insert(board[i][j]);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
