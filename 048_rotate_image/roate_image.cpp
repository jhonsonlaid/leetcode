class Solution{
public:
	void rotate(vector<vector<int>>& matrix){
		int ns = matrix.size();
		int p = (ns % 2 == 0) ? 0 : 1;
        // loop each circle
		for (int i = 0; i < ns / 2; i++){
			int start = ns / 2 - 1 - i;
			int end = start + 2 * (i + 1) + p - 1;
			for (int j = start; j < end; j++){
				// [t0 t1]
				// [t3 t2]
				int t0 = matrix[start][j];
				int t1 = matrix[j][end];
				int t2 = matrix[end][end-(j-start)];
				int t3 = matrix[end-(j-start)][start];
				matrix[j][end] = t0;
				matrix[end][end-(j-start)] = t1;
				matrix[end-(j-start)][start] = t2;
				matrix[start][j] = t3;
			}
		}
	}
};
