class Solution{
public:
    int minimumTotal(vector<vector<int>>& triangle){
        vector<vector<int>> dp;
        int n = triangle.size();
        for(int i = 0; i < n; i++){
            vector<int> row(triangle[i].begin(), triangle[i].end());
            dp.push_back(row);
            if(i == 0) continue;
            int m = triangle[i].size();
            for(int j = 0; j < m; j++){
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + row[j];
                else if(j == m-1){
                    dp[i][j] = dp[i-1][j-1] + row[j];
                }
                else
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + row[j];
            }
        }
        int min_path = INT_MAX;
        for(int j = 0; j < triangle[n-1].size(); j++){
            min_path = min(min_path, dp[n-1][j]);
        }
        return min_path;
    }
};
