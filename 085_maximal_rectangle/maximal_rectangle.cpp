class Solution{
public:
    int get_area(int r, int c, vector<vector<char>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        int min_w = n, max_area = 0;
        for(int i = r; i < m && matrix[i][c] != '0'; i++){
            int j = c;
            while(j < n && matrix[i][j] != '0') j++;
            min_w = min(min_w, j-c);
            int h = i - r + 1;
            // cout << min_w << " " << h << " " << r << c << endl;
            max_area = max(max_area, min_w * h);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix){
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), max_area = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // cout << i << " " << j << endl;
                max_area = max(max_area, get_area(i, j, matrix));
            }
        }
        return max_area;
    }
};
