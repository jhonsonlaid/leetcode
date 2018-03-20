class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        if(grid.empty()) return 0;
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> sum(r, vector<int>(c, 0));
        sum[0][0] = grid[0][0]; 
        for(int i = 1; i < c; i++)
            sum[0][i] = sum[0][i-1] + grid[0][i];
        for(int i = 1; i < r; i++)
            sum[i][0] = sum[i-1][0] + grid[i][0];
        for(int i = 1; i < r; i++)
            for(int j = 1; j < c; j++){
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        return sum[r-1][c-1];
    }
};
