class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(obstacleGrid[i][j] == 1){
                    if(i == 0)
                        for(int k = j; k < n; k++) dp[0][k] = 0;
                    if(j == 0)
                        for(int k = i; k < m; k++) dp[k][0] = 0;
                     dp[i][j] = 0;
                }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(dp[i][j] != 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
