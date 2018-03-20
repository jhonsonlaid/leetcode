/*** Using Dynamic Program ***
* define state dp[i][j] , p[0,j-1] matches s[0, i-1]
* i.e. |a|b| -->(index refer to the '|' index)
*
* // "a" match "ac*", "acc" also match "ac*"
* if p[j-1]=='*', dp[i][j] = dp[i][j-2] || 
* (p[j-2] == s[i-1] || p[j-2] ='.’) && dp[i-1][j]
*
* if p[j-1]!='*', dp[i][j] = dp[i-1][j-1] &&
* (p[j-1] == s[i-1] || p[j-1] = '.’)
*/

class Solution{
public:
    bool isMatch(string s, string p){
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
		if(!n) return false;
        // i start from 0 , as it may be empty string
		// if p = "", p[0] == NULL
        for(int i = 0; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(p[j-1] == '*')
					// only a* make sense, '*' only 
                    // and '*a' doesnot make sense, so j >= 2
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] 
								&& (s[i-1] == p[j-2] || p[j-2] == '.'));
                else
					dp[i][j] = i > 0 && dp[i-1][j-1] &&
								(s[i-1] == p[j-1] || p[j-1] == '.');
		return dp[m][n];
    }
};
