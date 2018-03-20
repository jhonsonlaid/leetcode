class Solution{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix){
		vector<int> res;
		if (matrix.empty()) return res;
		int m = matrix.size(), n = matrix[0].size();
		int num = min(m, n);
		for (int i = 0; i < num / 2; i++){
			//up
			for (int c = i; c <= n - i - 1; c++)
				res.push_back(matrix[i][c]);
			//right
			for (int r = i + 1; r < m - i - 1; r++)
				res.push_back(matrix[r][n - i - 1]);
			// bottom
			for (int c = n - i - 1; c > i; c--)
				res.push_back(matrix[m - i - 1][c]);
			//left
			for (int r = m - i - 1; r > i; r--)
				res.push_back(matrix[r][i]);
		}
		if (num % 2){
			int i = num / 2;
			if (m < n){
				for (int c = i; c <= n - i - 1; c++)
					res.push_back(matrix[i][c]);
			}
			else{
				for (int r = i; r <= m - i - 1; r++)
					res.push_back(matrix[r][n - i - 1]);
			}
		}
		return res;
	}
};
