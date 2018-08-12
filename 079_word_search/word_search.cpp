class Solution{
public:
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int r, int c, int k){
        if(k == word.size())
            return true;
        bool res = false;
        if(r >= 0 && r < board.size() &&
           c >= 0 && c < board[0].size() && !visited[r][c]){
            visited[r][c] = true;
            if(board[r][c] == word[k]){
                res = helper(board, visited, word, r-1, c, k+1) ||
                      helper(board, visited, word, r, c-1, k+1) ||
                      helper(board, visited, word, r+1, c, k+1) ||
                      helper(board, visited, word, r, c+1, k+1);
            }
            visited[r][c] = false;
        }
        return res;
    }
    bool exist(vector<vector<char>>& board, string word){
        int m = board.size(), n = board[0].size();
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if(helper(board, visited, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
