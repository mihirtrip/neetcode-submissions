class Solution {
   public:
    vector<vector<string>> ans;

    bool is_safe(vector<vector<int>> &curr, int n, int row, int col) {

    // Check same column
    for(int i = 0; i < row; i++) {
        if(curr[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    int i = row - 1;
    int j = col - 1;

    while(i >= 0 && j >= 0) {
        if(curr[i][j] == 1)
            return false;

        i--;
        j--;
    }

    // Check upper-right diagonal
    i = row - 1;
    j = col + 1;

    while(i >= 0 && j < n) {
        if(curr[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;
}

    vector<string> convert(vector<vector<int>> &curr){
        vector<string> ansi;
        for(int i =0;i<curr.size();i++){
            string temp = "";
            for(int  j=0;j<curr[i].size();j++){
                if(curr[i][j]==1){
                    temp += "Q";
                }
                else{
                    temp += ".";
                }
            }
            ansi.push_back(temp);
        }
        return ansi;
    }
    
    void solve(vector<vector<int>> &curr, int n, int index) {
        if (index == n) {
            vector<string> temp = convert(curr);
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            
            if(is_safe(curr,n,index,i)){
                curr[index][i] = 1;
                solve(curr,n, index+1);
                curr[index][i] = -1;
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> curr(n, vector<int>(n, -1));
        solve(curr, n,0);
        return ans;
    }
};
