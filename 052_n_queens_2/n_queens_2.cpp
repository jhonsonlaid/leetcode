class Solution{
public:
    int totalNQueens(int n){
        vector<string> cb(n, string(n, '.'));
        int count = 0;
        helper(cb, 0, count);
        return count;
    }

    void helper(vector<string> cb, int row, int count){
        if(row >= cb.size()) count++;
        for(int c = 0; c < cb.size(); c++){
            if(isValid(cb, row, c)){
                cb[row][c] = 'Q';
                helpr(cb, row+1, count);
                cb[row][c] = '.'
            }
        }
    }

    bool isValid(vecotr<string> cb, int row, int col){
        // col
        for(int i = 0 ; i < row; i++){
            if(cb[row][i] == 'Q') 
                return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && col >= 0; i--, j--){
            if(cb[i][j] == 'Q')
                return false;
        }
        for(int i = row + 1, j = col + 1; i <= cb.size() && col <= cb.size(); i++, j++){
            if(cb[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
