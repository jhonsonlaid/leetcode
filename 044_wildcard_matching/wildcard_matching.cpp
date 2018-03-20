/* Recursive version, time limit exceeded
 */
class Solution{
public:
	bool isMatch(string s, string p){
		
		int i = 0;
		while (p[i] == '*')
			i++;
		p = p.substr(max(i-1, 0));

		if (s.empty())
			if (p.empty())
				return true;
			else
				return p[0] == '*' ? isMatch(s, p.substr(1)) : false;
				
		if (p[0] != '*' && p[0] == '?' || p[0] == s[0])
			return isMatch(s.substr(1), p.substr(1));
		else if (p[0] == '*')
			return isMatch(s.substr(1), p) || isMatch(s, p.substr(1)) ;
		else
			return false;
	}
};
