/* refer to 010_reg
 */
class Solution{
public:
	bool isMatch(string s, string p){
		int slen = s.length(), plen = p.length();
		vector<vector<bool>> c(slen + 1, vector<bool>(plen + 1, false));
		c[0][0] = true;
		for (int i = 0; i <= slen; i++){
			for (int j = 1; j <= plen; j++){
				if (p[j - 1] != '*')
					c[i][j] = i > 0 && c[i-1][j-1] && (s[i - 1] == p[j - 1]
                            || p[j - 1] == '?');
				else
					c[i][j] = c[i][j - 1] || i > 0 && c[i - 1][j] || j == 1;
			}
		}
		return c[slen][plen];
	}
};
