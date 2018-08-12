class Solution{
public:
    int numDistinct(string s, string t){
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int j = 1; j <= n; j++){
            for(int i = j; i <= m ; i++){
                if(s[i-1] == t[j-1])
                    if(j != 1)
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j] + 1;
                else
                    dp[i][j] = dp[i-1][j];
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[m][n];
    }
};
