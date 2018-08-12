// Time Limited
class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
        int m = matrix.size();
        if(m == 0) return matrix;
        int n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                dist[i][j] = find_dist(matrix, visited, i, j);
            }
        }
        return dist;
    }
    
    int find_dist(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i , int j){
        int m = matrix.size(), n = matrix[0].size();
        if(!(i >= 0 && i <= m-1 && j >= 0 && j <= n-1))
            return 1e5;
        if (matrix[i][j] == 0) {
            visited[i][j]=true;
            return 0;
        }
        int left, right, up, down, min=1e5;
        if(!visited[i][j]){
            visited[i][j] = true;
            left = find_dist(matrix, visited, i, j-1);
            right = find_dist(matrix, visited, i, j+1);
            up = find_dist(matrix, visited, i+1, j);
            down = find_dist(matrix, visited, i-1, j);
            if(left < min) min = left;
            if(right < min) min = right;
            if(up < min) min = up;
            if(down < min) min = down;
            visited[i][j] = false;
        }
        return min + 1;
    }
};
