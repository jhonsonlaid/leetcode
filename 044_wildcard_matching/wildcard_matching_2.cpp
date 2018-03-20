/* iterative version
 */
class Solution{
public:
	bool isMatch(string s, string p){
		int slen = s.length(), plen = p.length();
		int si = -1, sj = -1, i = 0, j = 0;

		for (; i < slen; i++, j++){
			if (p[j] == '*'){
				si = i;
				sj = j;
				i--; // '*' feed null string
			}
			else{
				if (p[j] != s[i] && p[j] != '?'){
					if (sj >= 0){
						j = sj; // return to the nearest '*'
						i = si; // '*' feed s[si] char. so i will always grow
						si++;  // '*' greed next char
					}
					else{
						return false;
					}
				}
			}
		}
		while (p[j] == '*') j++;
		return j == plen;
	}
};
