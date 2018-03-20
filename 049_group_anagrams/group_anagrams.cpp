/* Time Limit Exceeded
 */
class Solution{
private:
	bool cmp(string s1, string s2){
		if (s1.size() != s2.size()) return false;
		while (!s1.empty()){
			bool match = false;
			// check if s1 char in s2 
			for (int j = 0; j < s2.size(); j++){
				if (s1[0] == s2[j]){
					s1.erase(s1.begin());
					s2.erase(s2.begin() + j);
					match = true;
					break;
				}
			}
			if(!match) return false;
		}
		return true;
	}
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs){
		vector<vector<string>> res;
		for (int i = 0; i < strs.size(); i++){
			// str[i].size anagrams
			int str_size = strs[i].size();
			bool in_res = false;
			// see if in res
			for (int j = 0; j < res.size(); j++){
				in_res = cmp(strs[i], res[j][0]);
				if (in_res) {
					res[j].push_back(strs[i]);
					break;
				}
			}
			if (!in_res){
				vector<string> tmp(1, strs[i]);
				res.push_back(tmp);
			}
		}
		return res;
	}
};
