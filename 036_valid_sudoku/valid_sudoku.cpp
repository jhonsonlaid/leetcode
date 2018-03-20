class Solution{
public:
    bool isValidSudoku(vector<vector<char>>& board){
        int row = board.size(), col = row;
        
        for(int i = 0; i < row; i++){
            // horizonal line
            map<char, int> h_line;
            for(int j = 0; j < col; j++){
                char ch = board[i][j];
                if(ch != '.' && h_line.find(ch) != h_line.end())
                    return false;
                else if( ch != '.')
                    h_line.insert(make_pair(ch, 1));
            }
            //vertical line 
            map<char, int> v_line;
            for(int j = 0; j < col; j++){        
                char ch = board[j][i];
                if(ch != '.' && v_line.find(ch) != v_line.end())
                    return false;
                else if( ch != '.')
                    v_line.insert(make_pair(ch, 1));
            }
        }
        
        for(int i = 0; i < row-2; i += 3){
            for(int j = 0; j < col-2; j += 3){
                map<char, int> s_board;
                for(int h = i; h < i+3; h++)
                    for(int k = j; k < j+3; k++){
                        char ch = board[h][k];
                        if(ch != '.' && s_board.find(ch) != s_board.end())
                            return false;
                        else if(ch != '.')
                            s_board.insert(make_pair(ch, 1));
                    }
            }
        }
        return true;
    }
};
