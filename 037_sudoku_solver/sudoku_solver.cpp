// Depth First Search

class Solution{
public:
    void solveSudoku(vector<vector<char>>& board){
        forward(board, 0);
    }

    bool forward(vector<vector<char>>& board, int pos){

        if(pos >= 81) return true;

        int r = pos / 9, l = pos % 9;

        if('.' != board[r][l]){
            return forward(board, pos+1);
		}
		else{
			for(char c = '1'; c <= '9'; c++){
        	    if(!inRow(board, r, c) && !inCol(board, l, c) && !inBlock(board, r, l, c)){

        	        board[r][l] = c;

        	        if(forward(board, pos+1)){
        	            return true;
        	        }
        	        else{
        	            board[r][l] = '.';
        	        }
        	    }
        	}
			return false;
		}
    }

    bool inRow(vector<vector<char>>& board, int r, char c){
        for(int j = 0; j < 9; j++){
            if(c == board[r][j]) return true;
        }
        return false;
    }

    bool inCol(vector<vector<char>>& board, int l, char c){
        for(int i = 0; i < 9; i++){
            if(c == board[i][l]) return true;
        }
        return false;
    }

    bool inBlock(vector<vector<char>>& board, int r, int l, char c){
        int rn = r / 3, ln = l / 3;
        for(int i = 3 * rn; i < 3 * (rn + 1); i++){
            for(int j = 3 * ln; j < 3 * (ln + 1); j++){
                if(c == board[i][j]) return true;
            }
		}
        return false;
    }
};
