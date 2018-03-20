class Solution{
public:
	vector<vector<string>> solveNQueens(int n){
		vector<vector<string>> res;
		vector<string> cb(n, string(n, '.'));
		helper(res, cb, 0);
		return res;
	}

	void helper(vector<vector<string>>& res, vector<string> cb, int row){
		if (row >= cb.size()){
			res.push_back(cb);
			return;
		}
		for (int c = 0; c < cb.size(); c++){
			if (!in_col(cb, row, c) && !in_diag(cb, row, c)){
				cb[row][c] = 'Q';
				helper(res, cb, row + 1);
				cb[row][c] = '.';
			}
		}
	}

	bool in_col(vector<string> cb, int row, int col){
		for (int i = 0; i < row; i++){
			if (cb[i][col] == 'Q')
				return true;
		}
		return false;
	}

	bool in_diag(vector<string> cb, int row, int col){
		for (int i = 1; i <= row; i++){
			if (col - i >= 0 && cb[row - i][col - i] == 'Q')
				return true;
			if (col + i < cb.size() && cb[row - i][col + i] == 'Q')
				return true;
		}
		return false;
	}
};

